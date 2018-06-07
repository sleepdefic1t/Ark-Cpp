

#ifndef VOTER_H
#define VOTER_H

#include "utilities/platform.h"
#include "types/address.h"
#include "types/balance.h"
#include "types/crypto/eckey.h"

#include <cstring>

namespace ARK
{    
class Voter :
		public Printable
{
	private:
		char username_[21] = { '\0' };
		Address address_;
		Publickey publicKey_;
		Balance balance_;

	public:
		Voter();

		Voter(
				const char* const newUsername, 
				const char* const newAddress, 
				const char* const newPublickey,
				const char* const newBalance
		);

		const char* username() const noexcept { return username_; }
		const Address address() const noexcept { return address_; }
		const Publickey& public_key() const noexcept { return publicKey_; }
		const Balance& balance() const noexcept { return balance_; }

		size_t printTo(Print& p) const override;

};

};

#endif
