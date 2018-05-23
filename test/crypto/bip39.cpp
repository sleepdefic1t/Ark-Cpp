#include "gtest/gtest.h"

#include "bip39/bip39.h"

#include <string>
#include <cstring>
#include <set>

TEST(crypto_bip39, generate_mnemonic) {
	auto passphrase = ARK::Crypto::BIP39::generate_mnemonic(ARK::Crypto::BIP39::language::en, 24);
	std::set<std::string> words;
	auto pch = strtok(passphrase.c_str(), ' ');
	while (pch != nullptr) {
		std::string word(pch);
		ASSERT_TRUE(words.insert(std::move(word)).second);
		pch = strtok(nullptr, ' ');
	}
	
	ASSERT_EQ(24, words.size());

	passphrase = ARK::Crypto::BIP39::generate_mnemonic(ARK::Crypto::BIP39::language::en, 12);
	words.clear();
	
	pch = strtok(passphrase.c_str(), ' ');
	while (pch != nullptr) {
		std::string word(pch);
		ASSERT_TRUE(words.insert(std::move(word)).second);
		pch = strtok(nullptr, ' ');
	}
	
	ASSERT_EQ(12, words.size());
}
