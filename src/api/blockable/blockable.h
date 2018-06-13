

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
* PUBLIC: ARK::API::Blockable
* public Block::Gettable
* virtual ARK::Utilities::Network::Connectable
*    
* API's Block Model
**************************************************/
class Blockable :
		virtual ARK::Utilities::Network::Connectable
{
	public:
		/*************************************************
		* /api/blocks/get?id=_blockID
		*
		* @param: const char *const blockId
		* @return: ARK::Block
		*
		* @brief: Uses Block ID to get that Blocks information from a Node via API.
		**************************************************/
		ARK::Block block(const char *const blockId);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getEpoch
		*
		* @param: char buffer[]
		*
		* @brief: Gets the Block Epoch from a Node via API.
		**************************************************/
		void blockEpoch(char buffer[]);
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getHeight
		*
		* @return: ARK::API::Block::Respondable::Height
		*
		* @brief: Gets the Block-Height from a Node via API.
		**************************************************/
		ARK::API::Block::Respondable::Height blockHeight();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getNethash
		*
		* @return: Hash
		* @brief: Gets the Networks Hash from a Node via API.
		**************************************************/
		Hash blockNethash();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getFee
		*
		* EXAMPLE:
		* {
		*   "success":true,
		*   "fee": Balance
		* }
		**************************************************/
		Balance blockFee();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getFees
		*
		* @return: ARK::Fees
		*
		* @brief: Gets Ark Network Fees from a Node via API.
		**************************************************/
		ARK::Fees blockFees();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getMilestone
		*
		* @return: const char*
		*
		* @brief: Gets the Block Milestone from a Node via API.
		**************************************************/
		const char *blockMilestone();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getReward
		*
		* @return: Balance
		*
		* @brief:	Gets the Block Reward from a Node via API.
		**************************************************/
		Balance blockReward();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getSupply
		*
		* @return: Balance
		*
		* @brief: Gets the current Ark Supply from a Node via API.

		**************************************************/
		Balance blockSupply();
		/*************************************************/

		/**************************************************************************************************/

		/*************************************************
		* /api/blocks/getStatus
		*
		* @return: ARK::API::Block::Respondable::Status
		*
		* @brief: Gets the Ark Networks Status from a Node via API.
		**************************************************/
		ARK::API::Block::Respondable::Status blockStatus();
		/*************************************************/

};
/*************************************************/

};
};

#endif


// 60k callback too big for arduino (~40k "unsafe" max for ESP8266). maybe implement a stream parser?
/**************************************************************************************************/
/*************************************************
* /api/blocks
**************************************************/
// ARK::API::Block::Respondable::Blocks blocks();
/*************************************************/
/**************************************************************************************************/
/*************************************************
* /api/blocks
*
* EXAMPLE:
* {
*   "success":true,
*   "blocks":
*	[
*		{
*			"id": char[],
*			"version": int,
*			"timestamp": char[],
*			"height": char[],
*			"previousBlock": char[],
*			"numberOfTransactions": char[],
*			"totalAmount": Balance,
*			"totalFee": Balance,
*			"reward": Balance,
*			"payloadLength": char[],
*			"payloadHash":  "Hash",
*			"generatorPublicKey": "Publickey",
*			"generatorId":  "Address",
*			"blockSignature": "Signature",
*			"confirmations":   char[],
*			"totalForged":" Balance"
*		},
*		...
*		{
*			"id": char[],
*			"version": int,
*			"timestamp": char[],
*			"height": char[],
*			"previousBlock": char[],
*			"numberOfTransactions": char[],
*			"totalAmount": Balance,
*			"totalFee": Balance,
*			"reward": Balance,
*			"payloadLength": char[],
*			"payloadHash":  "Hash",
*			"generatorPublicKey": "Publickey",
*			"generatorId":  "Address",
*			"blockSignature": "Signature",
*			"confirmations":   char[],
*			"totalForged":" Balance"
*		}
*	],
*	"count": 3639000
* }
**************************************************/
// ARK::API::Block::Respondable::Blocks ARK::API::Blockable::blocks()
// {
// 	char uri[31] = { '\0' };
// 		strcpy(uri, ARK::API::Paths::Block::blocks_s);
// 	auto callback = netConnector.callback(uri);
// 	auto parser = ARK::Utilities::makeJSONString(callback);
	// // Blocksigs are unique
	// // so lets find how many instances of "blockSignature" appear in the callback.
	// // this will give us a good idea of how many `block` elements exist
	// size_t blockCapacity = substringCount(callback.c_str(), "blockSignature"); 
	// // Dont confuse blockCapacity(^how many elements) from blockCount(˯"count" parameter)
	// unsigned int blockCount = convert_to_int(parser->valueFor("count").c_str());
	// ARK::API::Block::Respondable::Blocks blocks(blockCapacity, blockCount);

	// for (int i = 0; i < blockCapacity; i++)
	// {
	// 	blocks[i] = {
	// 		parser->subarrayValueIn("block", i, "id").c_str(),
	// 		convert_to_int(parser->subarrayValueIn("block", i, "version").c_str()),
	// 		parser->subarrayValueIn("block", i, "timestamp").c_str(),
	// 		parser->subarrayValueIn("block", i, "height").c_str(),
	// 		parser->subarrayValueIn("block", i, "previousBlock").c_str(),
	// 		parser->subarrayValueIn("block", i, "numberOfTransactions").c_str(),
	// 		parser->subarrayValueIn("block", i, "totalAmount").c_str(),
	// 		parser->subarrayValueIn("block", i, "totalFee").c_str(),
	// 		parser->subarrayValueIn("block", i, "reward").c_str(),
	// 		parser->subarrayValueIn("block", i, "payloadLength").c_str(),
	// 		parser->subarrayValueIn("block", i, "payloadHash").c_str(),
	// 		parser->subarrayValueIn("block", i, "generatorPublicKey").c_str(),
	// 		parser->subarrayValueIn("block", i, "generatorId").c_str(),
	// 		parser->subarrayValueIn("block", i, "blockSignature").c_str(),
	// 		parser->subarrayValueIn("block", i, "confirmations").c_str(),
	// 		parser->subarrayValueIn("block", i, "totalForged").c_str()
	// 	};
	// };
	// return blocks;
// };
/*************************************************/
/**************************************************************************************************/
