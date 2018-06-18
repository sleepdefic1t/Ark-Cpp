

#ifndef TRANSACTIONABLE_H
#define TRANSACTIONABLE_H

#include "api/transactionable/transaction_respondable.h"
#include "utilities/platform.h"
#include "types/hash.h"
#include "models/transaction.h"
#include "utilities/connector.h"
#include "api/paths.h"
#include "utilities/json.h"

#include <cstring>
#include <memory>

namespace ARK
{
namespace API
{
/*************************************************
* PUBLIC: ARK::API::Transactionable
* public Transaction::Gettable
* virtual ARK::Utilities::Network::Connectable
*    
* API's Peer Model
**************************************************/
class Transactionable :
		virtual ARK::Utilities::Network::Connectable
{
public:
	/*************************************************
	* /api/transactions/get?id=
	*
	* @method: transaction(Hash id)
	* @return: ARK::Transaction
	* @param: Hash id
	*
	* @brief: Gets Transaction by Hash ID from a Node via API.
	**************************************************/
	ARK::Transaction transaction(const Hash &id);
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	* /api/transactions?limit=20
	*
	* @brief: Gets Transactions list, limited to last 20.
	**************************************************/
	ARK::API::Transaction::Respondable::Transactions transactions();
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	* /api/transactions/unconfirmed/get?id=
	*
	* @method: transactionUnconfirmed(Hash id)
	* @return: const char*
	* @param: Hash id
	*
	* @brief: Gets Unconfirmed Transaction by Hash ID from a Node via API.
	**************************************************/
	ARK::API::Transaction::Respondable::Unconfirmed transactionUnconfirmed(const Hash &id);
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	* /api/transactions/unconfirmed
	*
	* @method: transactionsUnconfirmed()
	* @return: const char*
	*
	* @brief: Gets Unconfirmed Transactions from a Node via API.
	**************************************************/
	ARK::API::Transaction::Respondable::Unconfirmed transactionsUnconfirmed();
	/*************************************************/

	/**************************************************************************************************/

	/*************************************************
	* /api/transactions/get?id=
	*
	* @method: getVendorField(Hash txID)
	* @param: Hash txID
	*
	* @brief: Gets vendorField for a given Transaction by  txID from a Node via API.
	**************************************************/
	const char *getVendorField(const Hash &txID);
	/*************************************************/

};
/*************************************************/

};
};

#endif
