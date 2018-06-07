

#ifndef ACCOUNTABLE_H
#define ACCOUNTABLE_H

#include "utilities/platform.h"
#include "api/accountable/account_respondable.h"
#include "models/account.h"
#include "models/delegate.h"
#include "types/address.h"
#include "types/balance.h"
#include "types/crypto/eckey.h"
#include "utilities/connector.h"
#include "api/paths.h"
#include "utilities/json.h"

namespace ARK
{
namespace API
{
/*************************************************
*	PUBLIC: ARK::API::Accountable
*	public API::Account::Gettable
*	virtual ARK::Utilities::Network::Connectable
*    
*	API's Account Model
**************************************************/
class Accountable :
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		*	/api/accounts/getBalance?address=arkAddress
		*
		*	@param:	Address arkAddress
		*	@return:	ARK::API::Account::Respondable::Balances
		*
		*	@brief:	Uses Ark Address to get an Accounts Confirmed	and Unconfirmed Balances from a Node via API.
		**************************************************/
		ARK::API::Account::Respondable::Balances accountBalance(const Address &arkAddress);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	api/accounts/getPublickey?address=arkAddress
		*
		*	@param:	Address arkAddress
		*	@return:	Publickey
		*
		*	@brief:	Uses Ark Address to get an Accounts Publickey from a Node via API.
		**************************************************/
		Publickey accountPublickey(const Address &arkAddress);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/accounts/delegates/fee?address=arkAddress
		*
		*	@param:	Address arkAddress
		*	@return:	Balance
		*
		*	@brief:	Uses Ark Address to get Delegate Registration Fee from a Node via API.
		**************************************************/
		Balance accountDelegatesFee(const Address &arkAddress);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/accounts/delegates?address=arkAddress
		*
		*	@param:	Address arkAddress
		*	@return:	ARK::Delegate
		*
		*	@brief:	Uses Ark Address to get Delegate Object from a Node via API.
		**************************************************/
		ARK::Delegate accountDelegates(const Address &arkAddress);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/accounts?address=arkAddress
		*
		*	@param:	Address arkAddress
		*	@return:	ARK::Account
		*
		*	@brief:	Uses Ark Address to get Account Object from a Node via API.
		**************************************************/
		ARK::Account account(const Address &arkAddress);
		/*************************************************/

};
/*************************************************/

};
};

#endif
