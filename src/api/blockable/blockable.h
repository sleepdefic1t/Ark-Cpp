

#ifndef BLOCKABLE_H
#define BLOCKABLE_H

#include "utilities/platform.h"
#include "api/blockable/block_respondable.h"
#include "models/block.h"
#include "models/fees.h"
#include "utilities/connector.h"
#include "api/paths.h"
#include "utilities/json.h"

#include <memory>
#include <vector>

namespace ARK
{
namespace API
{
/*************************************************
*	PUBLIC: ARK::API::Blockable
*	public Block::Gettable
*	virtual ARK::Utilities::Network::Connectable
*    
*	API's Block Model
**************************************************/
class Blockable :
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		*	/api/blocks/get?id=_blockID
		*
		*	@param:	const char *const blockId
		*	@return:	ARK::Block
		*
		*	@brief:	Uses Block ID to get that Blocks information from a Node via API.
		**************************************************/
		ARK::Block block(const char *const blockId);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getEpoch
		*
		*	@param:	char buffer[]
		*
		*	@brief:	Gets the Block Epoch from a Node via API.
		**************************************************/
		void blockEpoch(char buffer[]);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getHeight
		*
		*	@return:	ARK::API::Block::Respondable::Height
		*
		*	@brief:	Gets the Block-Height from a Node via API.
		**************************************************/
		ARK::API::Block::Respondable::Height blockHeight();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getNethash
		*
		*	@return:	Hash
		*
		*	@brief:	Gets the Networks Hash from a Node via API.
		**************************************************/
		Hash blockNethash();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getFee
		*
		*	EXAMPLE:
		* {
		*   "success":true,
		*   "fee":  Balance
		* }
		**************************************************/
		Balance blockFee();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getFees
		*
		*	@return:	ARK::Fees
		*
		*	@brief:	Gets Ark Network Fees from a Node via API.
		**************************************************/
		ARK::Fees blockFees();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getMilestone
		*
		*	@return:	const char*
		*
		*	@brief:	Gets the Block Milestone from a Node via API.
		**************************************************/
		const char *blockMilestone();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getReward
		*
		*	@return:	Balance
		*
		*	@brief:	Gets the Block Reward from a Node via API.
		**************************************************/
		Balance blockReward();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getSupply
		*
		*	@return:	Balance
		*
		*	@brief:	Gets the current Ark Supply from a Node via API.

		**************************************************/
		Balance blockSupply();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		*	/api/blocks/getStatus
		*
		*	@return:	ARK::API::Block::Respondable::Status
		*
		*	@brief:	Gets the Ark Networks Status from a Node via API.
		**************************************************/
		ARK::API::Block::Respondable::Status blockStatus();
		/*************************************************/

};
/*************************************************/

};
};

#endif


/**************************************************************************************************/

/*************************************************/
/*************************************************
*	BROKEN: fix for large callbacks
*	blocks callback is ~63,712 bytes
**************************************************/
/*************************************************/
/*************************************************
* /api/blocks
**************************************************/
// String blocks()
// { return ARK::API::Block::Gettable::blocks(this->netConnector); };
/*************************************************/
/*************************************************/

/**************************************************************************************************/
