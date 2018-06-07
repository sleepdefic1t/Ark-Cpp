

#include "models/network.h"

/*************************************************
*	Constructor
**************************************************/
ARK::Network::Network(
		const char *const newNethash,
		const char *const newToken,
		const char *const newSymbol,
		const char *const newExplorer,
		int newVersion
)	: nethash_(newNethash),
		token_(),
		symbol_(),
		explorer_(),
		version_(newVersion)
{
	strncpy( this->token_, newToken, sizeof(this->token_) / sizeof(this->token_[0]) );
	for (unsigned int i = 0; i < strlen(newSymbol); i++)
	{
		( sizeof(newSymbol[i]) == sizeof(char) )
				? ( this->symbol_[i] = newSymbol[i] )
				: ( sprintf(this->symbol_, "%2c", newSymbol[i]) );
	}
	strcat(this->symbol_, "\0");
	strncpy(this->explorer_, newExplorer, sizeof(this->explorer_) / sizeof(this->explorer_[0]));
}
/*************************************************/

/*************************************************
*
**************************************************/
size_t ARK::Network::printTo(Print &p) const
{
	size_t size = 0;
	size += p.print("\nnethash: ");
	size += p.print(this->nethash_);

	size += p.print("\ntoken: ");
	size += p.print(this->token_);

	size += p.print("\nsymbol: ");
	size += p.print(this->symbol_);

	size += p.print("\nexplorer: ");
	size += p.print(this->explorer_);

	size += p.print("\nversion: ");
	size += p.print(this->version_);
	return size;
}
/*************************************************/

/*************************************************
*	ARK::Network::Network::operator==
*
*	@brief:	Comparison of two Network Models for equality.
**************************************************/
bool ARK::Network::Network::operator==(const Network &rhs) const
{
	return (
		strcmp(this->nethash_, rhs.nethash()) == 0
			&& strcmp(this->token_, rhs.token()) == 0 && strcmp(this->symbol_, rhs.symbol()) == 0
			&& strcmp(this->explorer_, rhs.explorer()) == 0
			&& this->version_ == rhs.version()
	);
}
/*************************************************/

/*************************************************
*	ARK::Network::Network::operator!=
*
*	@brief:	Comparison of two Network Models for inequality.
**************************************************/
bool ARK::Network::Network::operator!=(const Network &rhs) const { return !(*this == rhs); }
/*************************************************/
