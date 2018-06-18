

#include "api/delegatable/delegatable.h"

/*************************************************
* /api/delegates/get?username=sleepdeficit
*
* EXAMPLE:
* { 
*	"success":true,
*	"delegate":
* 	{
*		"username": "sleepdeficit",
*		"address":  "Address",
*		"publicKey":  "Publickey",
*		"vote": "Balance",
*		"producedblocks": const char*,
*		"missedblocks": const char*,
*		"rate": int,
*		"approval": double,
*		"productivity": double
*	}
* }
**************************************************/
ARK::Delegate ARK::API::Delegatable::delegate(
		const char *const parameter
) {
	char uri[120 + 1] = { '\0' };	//max size (pubkey param)
		strcpy(uri, ARK::API::Paths::Delegate::get_s);

	bool isUsername = (strlen(parameter) <= 20);
	auto key = (isUsername) ? ("?username=") : ("?publicKey=");
		strcat(uri, key);
		strcat(uri, parameter);

	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return {
		parser->valueIn("delegate", "username").c_str(),
		parser->valueIn("delegate", "address").c_str(),
		parser->valueIn("delegate", "publicKey").c_str(),
		parser->valueIn("delegate", "vote").c_str(),
		convert_to_int(parser->valueIn("delegate", "producedblocks").c_str()),
		convert_to_int(parser->valueIn("delegate", "missedblocks").c_str()),
		convert_to_int(parser->valueIn("delegate", "rate").c_str()),
		convert_to_float(parser->valueIn("delegate", "approval").c_str()),
		convert_to_float(parser->valueIn("delegate", "productivity").c_str())
	};
};
/*************************************************/

/**************************************************************************************************/
		
/*************************************************
* /api/delegates?limit=20
*
* @return: ARK::API::Delegate::Respondable::Delegates
*
* @brief: Returns Delegates list, limited to top 20 to fit MCU.
*
*
* EXAMPLE:
* { 
*	"success":true,
*	"delegates":
*	[
*		{
*			"username": "string",
*			"address":  "Address",
*			"publicKey":  "Publickey",
*			"vote": "Balance",
*			"producedblocks": const char*,
*			"missedblocks": const char*,
*			"rate": int,
*			"approval": double,
*			"productivity": double
* 		},
*		...
*		{
*			"username": "string",
*			"address":  "Address",
*			"publicKey":  "Publickey",
*			"vote": "Balance",
*			"producedblocks": const char*,
*			"missedblocks": const char*,
*			"rate": int,
*			"approval": double,
*			"productivity": double
* 		}
*	]
*	totalCount: 227
* }
**************************************************/
ARK::API::Delegate::Respondable::Delegates ARK::API::Delegatable::delegates()
{
	char uri[43] = { '\0' };
		strcpy(uri, ARK::API::Paths::Delegate::delegates_s);
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);

	const size_t maxCapacity = 20; // limit to top 20 delegates to fit MCU's.
	ARK::API::Delegate::Respondable::Delegates delegates(maxCapacity);

	for (int i = 0; i < maxCapacity; i++)
	{
		delegates[i] = {
			parser->subarrayValueIn("delegates", i, "username").c_str(),
			parser->subarrayValueIn("delegates", i, "address").c_str(),
			parser->subarrayValueIn("delegates", i, "publicKey").c_str(),
			parser->subarrayValueIn("delegates", i, "vote").c_str(),
			convert_to_int(parser->subarrayValueIn("delegates", i, "producedblocks").c_str()),
			convert_to_int(parser->subarrayValueIn("delegates", i, "missedblocks").c_str()),
			convert_to_int(parser->subarrayValueIn("delegates", i, "rate").c_str()),
			convert_to_float(parser->subarrayValueIn("delegates", i, "approval").c_str()),
			convert_to_float(parser->subarrayValueIn("delegates", i, "productivity").c_str())
		};
	};
	delegates.setTotalCount( convert_to_int(parser->valueFor("totalCount").c_str()) );
	return delegates;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/delegates/count
*
* EXAMPLE:
* { 
*	"success":true,
*	"count":166
* }
**************************************************/
int ARK::API::Delegatable::delegatesCount()
{
	auto callback = netConnector.callback(ARK::API::Paths::Delegate::count_s);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return convert_to_int(parser->valueFor("count").c_str());
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/delegates/search?q=sleepdeficit 
*
* EXAMPLE:
* { 
*	"success":true,
*	"delegates":
*	[
*		{ 
*			"username":"_username",
*			"address":"_arkAddress",
*			"publicKey":"_pubkey",
*			"vote":"0000000000000",
*			"producedblocks":0,
*			"missedblocks":0
*		}
*	]
* }
**************************************************/
ARK::API::Delegate::Respondable::Search ARK::API::Delegatable::delegateSearch(
		const char *const username
) {
	char uri[69 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Delegate::search_s);
		strcat(uri, "?q=");
		strcat(uri, username);
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return {
		parser->subarrayValueIn("delegates", 0, "username").c_str(),
		parser->subarrayValueIn("delegates", 0, "address").c_str(),
		parser->subarrayValueIn("delegates", 0, "publicKey").c_str(),
		parser->subarrayValueIn("delegates", 0, "vote").c_str(),
		convert_to_int(parser->subarrayValueIn("delegates", 0, "producedblocks").c_str()),
		convert_to_int(parser->subarrayValueIn("delegates", 0, "missedblocks").c_str())
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/delegates/voters?publicKey=_pubKey
*
* EXAMPLE:
* {
*	"success":true,
*	"accounts":
*	[
*		{ 
*			"username": "const char*",
*			"address":  "Balance",
*			"publicKey":  "Publickey",
*			"balance":  "Balance"
*		},
*		{
*			"username": "const char*",
*			"address":  "Address",
*			"publicKey":  "Publickey",
*			"balance":  "Balance"
*		}
*	]
* }
**************************************************/
ARK::API::Delegate::Respondable::Voters ARK::API::Delegatable::delegateVoters(
		const Publickey &publicKey
) {
	char uri[123 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Delegate::voters_s);
		strcat(uri, "?publicKey=");
		strcat(uri, publicKey.c_str());
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);

	int voterCount = substringCount(callback.c_str(), "username");
	ARK::API::Delegate::Respondable::Voters voters(voterCount);

	for (int i = 0; i < voterCount; ++i)
	{
		voters[i] = {
			parser->subarrayValueIn("accounts", i, "username").c_str(),
			parser->subarrayValueIn("accounts", i, "address").c_str(),
			parser->subarrayValueIn("accounts", i, "publicKey").c_str(),
			parser->subarrayValueIn("accounts", i, "balance").c_str()
		};
	};
	return voters;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/delegates/fee
*
* EXAMPLE:
* {
*	"success":true,
*	"fee":  Balance
* }
**************************************************/
Balance ARK::API::Delegatable::delegateFee()
{
	auto callback = netConnector.callback(ARK::API::Paths::Delegate::fee_s);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return Balance(parser->valueFor("fee").c_str());
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey
*
* EXAMPLE:
* {
*	"success":true,
*	"fees": "Balance",
*	"rewards":  "Balance",
*	"forged": "Balance"
* }
**************************************************/
ARK::API::Delegate::Respondable::ForgedByAccount ARK::API::Delegatable::delegateForgedByAccount(
		const Publickey &generatorPublicKey
) {
	char uri[152 + 1];
		strcpy(uri, ARK::API::Paths::Delegate::getForgedByAccount_s);
		strcat(uri, "?generatorPublicKey=");
		strcat(uri, generatorPublicKey.c_str());

	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return {
		parser->valueFor("fees").c_str(),
		parser->valueFor("rewards").c_str(),
		parser->valueFor("forged").c_str()
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/delegates/getNextForgers
*
* EXAMPLE:
* { 
*	"success":true,
*	"currentBlock":2307497,
*	"currentSlot":3189409,
*	"delegates":
*	[
*		"035ce69858a12a5ac31575c35c7c87a84a1b6a0455697d7015ea756a880aef05c0",
*		"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456",
*		"028f0a25321cd9d3bf051b34a835cd5eee0125120c17654bc95790f8f2d970dc46",
*		"027d607ba6226b302357aa9b4bb75d0e44761780492f0b38b267d2962d242e6a52",
*		"02b7b740973db16cd9c6f0f6f2bc160d27cd2a855e172d887833141bec234eb80c",
*		"0212ba6565ea6900ecf1fc5eee172f74aff8b22963be5d0d60e7f773db0055cbd2",
*		"02524ea2e2e9bad0ecbe521756388bf65e0b09dd2877d96495fe60200a97b35ddb",
*		"02dc13fcb190bcfbe9e7ecfc6269635ed2c497a75bab471f2b15c1a99897da97b3",
*		"022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d",
*		"031f3dffe4d10f78d85806d6b46f9c9a116e1aa56e8c538da2e02a416ff654b1db"
*	]
* }
**************************************************/
ARK::API::Delegate::Respondable::NextForgers ARK::API::Delegatable::delegateNextForgers()
{
	auto callback = netConnector.callback(ARK::API::Paths::Delegate::getNextForgers_s);
	auto parser = ARK::Utilities::makeJSONString(callback);

	Publickey delegateKeys[10];
	for (int i = 0; i < 10; ++i)
	{
		delegateKeys[i] = parser->subvalueFor("delegates", i).c_str();
	};
	return {
		convert_to_int(parser->valueFor("currentBlock").c_str()),
		convert_to_int(parser->valueFor("currentSlot").c_str()),
		delegateKeys
	};
};
/*************************************************/
