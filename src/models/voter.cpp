

#include "models/voter.h"
	
ARK::Voter::Voter() :
		username_(),
		address_(),
		publicKey_(),
		balance_() { }

ARK::Voter::Voter(
		const char* const newUsername, 
		const char* const newAddress, 
		const char* const newPublickey,
		const char* const newBalance
) 	:	address_(newAddress),
		publicKey_(newPublickey),
		balance_(newBalance)
{
	strncpy(username_, newUsername, strlen(newUsername));
}

size_t ARK::Voter::printTo(Print& p) const 
{
	size_t size = 0;

	size += p.print("\nusername: ");
	size += p.print(this->username_);

	size += p.print("\naddress: ");
	size += p.print(this->address_.c_str());

	size += p.print("\npublicKey: ");
	size += p.print(this->publicKey_.c_str());

	size += p.print("\nbalance.ark: ");
	size += p.print(this->balance_.ark());

	return size;
}
