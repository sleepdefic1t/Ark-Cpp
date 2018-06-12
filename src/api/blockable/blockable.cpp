


#include "api/blockable/blockable.h"

/*************************************************
* /api/blocks/get?id=_blockID
*
* EXAMPLE:
* {
*   "success":true,
*   "block":
*   {
*     "id": "const char*",
*     "version":  int,
*     "timestamp":  const char*,
*     "height": const char*,
*     "previousBlock":  "const char*",
*     "numberOfTransactions": const char*,
*     "totalAmount":  Balance,
*     "totalFee": Balance,
*     "reward": Balance,
*     "payloadLength":  const char*,
*     "payloadHash":  "Hash",
*     "generatorPublicKey": "Publickey",
*     "generatorId":  "Address",
*     "blockSignature": "Signature",
*     "confirmations":  const char*,
*     "totalForged":" Balance"
*   }
* }
**************************************************/
ARK::Block ARK::API::Blockable::block(
		const char *const blockId
) {
	char uri[80] = { '\0' };
		strcpy(uri, ARK::API::Paths::Block::get_s);
		strcat(uri, "?id=");
		strcat(uri, blockId);
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return {
		parser->valueIn("block", "id").c_str(),
		convert_to_int(parser->valueIn("block", "version").c_str()),
		parser->valueIn("block", "timestamp").c_str(),
		parser->valueIn("block", "height").c_str(),
		parser->valueIn("block", "previousBlock").c_str(),
		parser->valueIn("block", "numberOfTransactions").c_str(),
		parser->valueIn("block", "totalAmount").c_str(),
		parser->valueIn("block", "totalFee").c_str(),
		parser->valueIn("block", "reward").c_str(),
		parser->valueIn("block", "payloadLength").c_str(),
		parser->valueIn("block", "payloadHash").c_str(),
		parser->valueIn("block", "generatorPublicKey").c_str(),
		parser->valueIn("block", "generatorId").c_str(),
		parser->valueIn("block", "blockSignature").c_str(),
		parser->valueIn("block", "confirmations").c_str(),
		parser->valueIn("block", "totalForged").c_str()
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getEpoch
*
* EXAMPLE:
* {
*   "success":true,
*   "epoch":  "String"
* }
**************************************************/
void ARK::API::Blockable::blockEpoch(
		char buffer[]
) {
	auto callback = netConnector.callback(ARK::API::Paths::Block::getEpoch_s);
	auto parser = ARK::Utilities::makeJSONString(callback);
	strcpy(buffer, parser->valueFor("epoch").c_str());
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getHeight
*
* EXAMPLE:
* {
*   "success":true,
*   "height": String,
*   "id": "String"
* }
**************************************************/
ARK::API::Block::Respondable::Height ARK::API::Blockable::blockHeight()
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getHeight_s);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return { parser->valueFor("height").c_str(), parser->valueFor("id").c_str() };
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getNethash
*
* EXAMPLE:
* {
*   "success":true,
*   "nethash":  "Hash"
* }
**************************************************/
Hash ARK::API::Blockable::blockNethash()
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getNethash_s);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return Hash(parser->valueFor("nethash").c_str());
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getFee
*
* EXAMPLE:
* {
*   "success":true,
*   "fee":  Balance
* }
**************************************************/
Balance ARK::API::Blockable::blockFee()
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getFee_s);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return Balance(parser->valueFor("fee").c_str());
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getFees
*
* EXAMPLE:
*
* {
*   "success":true,
*   "fees":
*   {
*     "send": Balance,
*     "vote": Balance,
*     "secondsignature": Balance,
*     "delegate": Balance,
*     "multisignature": Balance
*   }
* }
**************************************************/
ARK::Fees ARK::API::Blockable::blockFees()
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getFees_s);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return {
		parser->valueIn("fees", "send").c_str(),
		parser->valueIn("fees", "vote").c_str(),
		parser->valueIn("fees", "secondsignature").c_str(),
		parser->valueIn("fees", "delegate").c_str(),
		parser->valueIn("fees", "multisignature").c_str()
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getMilestone
*
* EXAMPLE:
* {
*   "success":true,
*   "milestone": String
* }
**************************************************/
const char *ARK::API::Blockable::blockMilestone()
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getMilestone_s);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return parser->valueFor("milestone").c_str();
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getReward
*
* EXAMPLE:
* { 
*   "success":true,
*   "reward": Balance
* }
**************************************************/
Balance ARK::API::Blockable::blockReward()
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getReward_s);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return Balance(parser->valueFor("reward").c_str());
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getSupply
*
* EXAMPLE:
* {
*   "success":true,
*   "supply": Balance
* }
**************************************************/
Balance ARK::API::Blockable::blockSupply()
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getSupply_s);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return Balance(parser->valueFor("supply").c_str());
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/blocks/getStatus
*
* EXAMPLE:
* {
*   "success":true,
*   "epoch":  "String",
*   "height": String,
*   "fee":  Balance,
*   "milestone":  String,
*   "nethash":" Hash",
*   "reward":_reward,
*   "supply":_supply
* }
**************************************************/
ARK::API::Block::Respondable::Status ARK::API::Blockable::blockStatus()
{
	auto callback = netConnector.callback(ARK::API::Paths::Block::getStatus_s);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return {
		parser->valueFor("epoch").c_str(),
		parser->valueFor("height").c_str(),
		parser->valueFor("fee").c_str(),
		convert_to_int(parser->valueFor("milestone").c_str()),
		parser->valueFor("nethash").c_str(),
		parser->valueFor("reward").c_str(),
		parser->valueFor("supply").c_str()
	};
};
/*************************************************/
