

#include "crypto/ark_crypto.h"

namespace ARK
{
namespace Crypto
{

std::string getAddress(
	uint8_t network,
	const std::vector<uint8_t>& public_key
) {
	std::vector<uint8_t> seed(Ripemd160::HASH_LEN);
	Ripemd160::getHash(
		&public_key[0],
		public_key.size(),
		&seed[0]
	);
	std::string s(35, '\0');
	Base58Check::pubkeyHashToBase58Check(
		network,
		&seed[0],
		&s[0]
	);
	return s;
}

Account createAccount(
	uint8_t network,
	const char* const passphrase
) {
	std::vector<uint8_t> priv_key(PRIVATE_KEY_SIZE);
	std::vector<uint8_t> pub_key(COMPRESSED_PUBLIC_KEY_SIZE);
	getKeys(passphrase, priv_key, pub_key);
	const auto address = getAddress(network, pub_key);
	return Account(BytesToHex(pub_key).c_str(), address.c_str());
}

void getKeys(
	const char* const passphrase,
	std::vector<uint8_t>& priv_key,
	std::vector<uint8_t>& pub_key,
	bool compressed /* = true */
) {
	getPrivkey(passphrase, priv_key);
	getPubkey(priv_key, pub_key, compressed);
}

void getPrivkey(
	const char* const passphrase,
	std::vector<uint8_t>& priv_key
) {
	auto hash = Sha256::getHash(
		reinterpret_cast<const unsigned char*>(passphrase),
		std::strlen(passphrase)
	);
	std::memcpy(&priv_key[0], hash.value, priv_key.size());
}

void getPubkey(
	const std::vector<uint8_t>& priv_key,
	std::vector<uint8_t>& pub_key,
	bool compressed /* = true */
) {
	const struct uECC_Curve_t * curve = uECC_secp256k1();
	uint8_t pub[64] = {};
	// TODO: using the current uECC implementation, a private key value of "1" will return a false negative.  
	// It appears to be not supported given the following issue: https://github.com/kmackay/micro-ecc/issues/128
	auto ret = uECC_compute_public_key(&priv_key[0], pub, curve);  // Don't check the return inline with the assert.  MSVC optimizer does bad things.
	assert(ret != 0);
	if (compressed)
	{
		assert(pub_key.size() == COMPRESSED_PUBLIC_KEY_SIZE);
		uECC_compress(pub, &pub_key[0], curve);
	} else {
		assert(pub_key.size() == PUBLIC_KEY_SIZE);
		// Add the 0x04 prefix since the framework doesn't do it for us
		// see: https://github.com/kmackay/micro-ecc#point-representation
		pub_key[0] = 0x04;
		std::memcpy(&pub_key[1], pub, PUBLIC_KEY_SIZE - 1);
	}
}

std::string toWIF(
	uint8_t version,
	const uint8_t key[PRIVATE_KEY_SIZE],
	bool compressed /* = true */
){
	//assert(key.size() == PRIVATE_KEY_SIZE); // "private key must be 32 bytes"
#if 0
	std::vector<uint8_t> buf(compressed ? 34 : 33);
	buf[0] = version;
	for (auto i = 1u; i < 33; ++i) {
		buf[i] = key[i - 1];
	}
	if (compressed) {  buf[33] = 0x01; }
#endif
	std::string s(53, '\0');
	Base58Check::privateKeyToBase58Check(
			version,
			compressed,
			Uint256(
				BytesToHex(
					key,
					key + PRIVATE_KEY_SIZE
				).c_str()),
			&s[0]);
	return s;
}

void fromWIF(
	const std::string& wif,
	uint8_t& version,
	uint8_t priv_key[PRIVATE_KEY_SIZE],
	bool& compressed
) {
	Uint256 bi;
	auto ret = Base58Check::privateKeyFromBase58Check(wif.c_str(), bi, version, compressed);
	assert(ret);
	bi.getBigEndianBytes(priv_key);
}

};
};
