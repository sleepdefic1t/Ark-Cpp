

#ifndef DELEGATABLE_H
#define DELEGATABLE_H

#include "api/delegatable/delegate_respondable.h"

#include "utilities/platform.h"
#include "models/delegate.h"
#include "utilities/connector.h"
#include "api/paths.h"
#include "utilities/json.h"

namespace ARK
{
namespace API
{
/*************************************************
* PUBLIC: ARK::API::Delegatable
* public API::Delegate::Gettable
* virtual ARK::Utilities::Network::Connectable
*    
* API's Delegate Model
**************************************************/
class Delegatable :
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		* /api/delegates/get?username=sleepdeficit
		*
		* @param: const char* const parameter
		* @return: ARK::API::Delegate::Respondable::Voters
		*
		* @brief: Returns Delegate by username from a Node via API.
		**************************************************/
		ARK::Delegate delegate(const char *const parameter);
		/*************************************************/

		/**************************************************************************************************/
		
		/*************************************************
		* /api/delegates/count
		*
		* @return: int
		*
		* @brief: Gets current number of registered Delegates from a Node via API.
		**************************************************/
		int delegatesCount();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/delegates/search?q=sleepdeficit 
		*
		* @param: const char* const username
		* @return: ARK::API::Delegate::Respondable::Search
		*
		* @brief: Searches for Delegate by username from a Node via API.
		**************************************************/
		ARK::API::Delegate::Respondable::Search delegateSearch(const char *const username);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/delegates/voters?publicKey=_pubKey
		*
		* @param: const Publickey &publicKey
		* @return: ARK::API::Delegate::Respondable::Voters
		*
		* @brief:	Returns Voters list for Delegate by Publickey from a Node via API.
		**************************************************/
		ARK::API::Delegate::Respondable::Voters delegateVoters(const Publickey &publicKey);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/delegates/fee
		*
		* @return: Balance
		*
		* @brief: Returns Delegate Registration Fee from a Node via API.
		**************************************************/
		Balance delegateFee();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey
		*
		* @param: const Publickey& generatorPublicKey
		* @return: ARK::API::Delegate::Respondable::ForgedByAccount
		*
		* @brief:	Returns Totals of Amounts Forged by Delegate by Publickey from a Node via API.
		**************************************************/
		ARK::API::Delegate::Respondable::ForgedByAccount delegateForgedByAccount(const Publickey &generatorPublicKey);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/delegates/getNextForgers
		*
		* @return: ARK::API::Delegate::Respondable::NextForgers
		*
		* @brief:	Returns next 10 Forging-Delegates from a Node via API.
		**************************************************/
		ARK::API::Delegate::Respondable::NextForgers delegateNextForgers();
		/*************************************************/

	};
	/*************************************************/

};
};

#endif


/*************************************************/
/*	BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
/*  /api/delegates  */
/*************************************************
	* /api/blocks/get?id=_blockID
	**************************************************/
// String getDelegates()
// { return ARK::API::DelegateGettable::delegates(this->netConnector); };
// /*  =====================  */
// /*  ARK::DelegateResponse  */
// struct DelegatesResponse
// {
// public:
// 	int count;
// 	ARK::Delegate list[5]; // = {{}};
// 	DelegatesResponse(int);
// 	String description();
// };
// /*  =====================  */
/*  =============  */
/*  ARK::DelegatesResponse  */
/*  Constructor  */
// ARK::DelegatesResponse::DelegatesResponse(int _count)
// {
//         this->count = _count;
// }
/*  =====  */
/*  Description  */
// String ARK::DelegatesResponse::DelegatesResponse::description()
// {
//		String resp;
//		if (this->count > 0)
//		{
//			for (int i = 0; i < this->count; i++)
//			{
//				resp += "\ndelegate ";
//				resp += i + 1;
//				resp += ":\n";
//				resp += this->list[i].description();
//				resp += "\n";
//			};
//		};
//		return resp;
// }
