

#ifndef ARK_CRYPTO_H
#define ARK_CRYPTO_H

#include "utilities/platform.h"
#include "utilities/formatting.h"
#include "models/account.h"

#include "constants/networks.h"

#include "bcl/Utils.hpp"
#include "bcl/Base58Check.hpp"
#include "bcl/CurvePoint.hpp"
#include "bcl/Ecdsa.hpp"
#include "bcl/FieldInt.hpp"
#include "bcl/Ripemd160.hpp"
#include "bcl/Sha256Hash.hpp"
#include "bcl/Sha256.hpp"
#include "bcl/Sha512.hpp"
#include "bcl/Uint256.hpp"

#if defined(USE_IOT)
	#include "uECC.h"
#else
	#include "uECC/uECC.h"
#endif

#include <cassert>
#include <string>
#include <vector>


namespace ARK
{
namespace Crypto
{

	const auto PUBLIC_KEY_SIZE = 65u;
	const auto COMPRESSED_PUBLIC_KEY_SIZE = 33u;
	const auto PRIVATE_KEY_SIZE = 32u;

	void getKeys(
			const char* const passphrase,
			std::vector<uint8_t>& priv_key,
			std::vector<uint8_t>& pub_key,
			bool compressed = true
	);

	void getPrivkey(
			const char* const passphrase,
			std::vector<uint8_t>& priv_key
	);

	void getPubkey(
			const std::vector<uint8_t>& priv_key,
			std::vector<uint8_t>& pub_key,
			bool compressed = true
	);

	std::string toWIF(
			uint8_t version,
			const uint8_t key[PRIVATE_KEY_SIZE],
			bool compressed = true
	);
	void fromWIF(
			const std::string& wif,
			uint8_t& version,
			uint8_t priv_key[PRIVATE_KEY_SIZE],
			bool& compressed
	);

	std::string getAddress(
			uint8_t network,
			const std::vector<uint8_t>& public_key
	);

	Account createAccount(
			uint8_t network,
			const char* const passphrase
	);

};
};

#endif
