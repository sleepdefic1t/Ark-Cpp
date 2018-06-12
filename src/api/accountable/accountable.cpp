

#include "api/accountable/accountable.h"


/*************************************************
*	/api/accounts/getBalance?address=arkAddress
*
*	EXAMPLE:
*	{
*		"success":true,
*		"balance":  "Balance",
*		"unconfirmedBalance": "Balance"
*	}
**************************************************/
ARK::API::Account::Respondable::Balances ARK::API::Accountable::accountBalance(
		const Address &arkAddress
) {
	char uri[68 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Account::getBalance_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.c_str());
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return {
		parser->valueFor("balance").c_str(),
		parser->valueFor("unconfirmedBalance").c_str()
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	api/accounts/getPublickey?address=arkAddress
*
*	EXAMPLE:
*	{
*		"success":true,
*		"publicKey":  "Publickey"
*	}
**************************************************/
Publickey ARK::API::Accountable::accountPublickey(
		const Address &arkAddress
) {
	char uri[94 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Account::getPublickey_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.c_str());
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return {
		parser->valueFor("publicKey").c_str()
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/accounts/delegates/fee?address=arkAddress
*
* EXAMPLE:
* {
* 	"success":true,
* 	"fee":2500000000
* }
**************************************************/
Balance ARK::API::Accountable::accountDelegatesFee(
		const Address &arkAddress
) {
	char uri[95 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Account::delegatesFee_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.c_str());
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return Balance(parser->valueFor("fee").c_str());
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/accounts/delegates?address=arkAddress
*
* EXAMPLE:
*	{
*		"success":true,
*		"delegates":
*		[
*			{
*				"username": "sleepdeficit",
*				"address":  "Address",
*				"publicKey":  "Publickey",
*				"vote": "Balance",
*				"producedblocks": const char*,
*				"missedblocks": String,
*				"rate": int,
*				"approval": double,
*				"productivity": double
*			}
*		]
*	}
**************************************************/
ARK::Delegate ARK::API::Accountable::accountDelegates(
		const Address &arkAddress
) {
	char uri[91 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Account::delegates_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.c_str());
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return {
		parser->subarrayValueIn("delegates", 0, "username").c_str(),
		parser->subarrayValueIn("delegates", 0, "address").c_str(),
		parser->subarrayValueIn("delegates", 0, "publicKey").c_str(),
		parser->subarrayValueIn("delegates", 0, "vote").c_str(),
		convert_to_int(parser->subarrayValueIn("delegates", 0, "producedblocks").c_str()),
		convert_to_int(parser->subarrayValueIn("delegates", 0, "missedblocks").c_str()),
		convert_to_int(parser->subarrayValueIn("delegates", 0, "rate").c_str()),
		convert_to_float(parser->subarrayValueIn("delegates", 0, "approval").c_str()),
		convert_to_float(parser->subarrayValueIn("delegates", 0, "productivity").c_str())
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	/api/accounts?address=arkAddress
*
*	EXAMPLE:
*	{
*		"success":true,
*		"account":
*		{
*			"address":  "Address",
*			"unconfirmedBalance": "Balance",
*			"balance":  "Balance",
*			"publicKey":  "Publickey",
*			"unconfirmedSignature": int,
*			"secondSignature":  int,
*			"secondPublicKey":  "Publickey",
*			"multisignatures":[],
*			"u_multisignatures":[]
*		}
*	}
**************************************************/
ARK::Account ARK::API::Accountable::account(
		const Address &arkAddress
) {
	char uri[81 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Account::accounts_s);
		strcat(uri, "?address=");
		strcat(uri, arkAddress.c_str());
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);
		/********************
		*	FIXME 
		* multisignatures & u_multisignatures returns an array of Transaction ID's (Hash type)
		********************/
	return {
		parser->valueIn("account", "address").c_str(),
		parser->valueIn("account", "unconfirmedBalance").c_str(),
		parser->valueIn("account", "balance").c_str(),
		parser->valueIn("account", "publicKey").c_str(),
		convert_to_int(parser->valueIn("account", "unconfirmedSignature").c_str()),
		convert_to_int(parser->valueIn("account", "secondSignature").c_str()),
		parser->valueIn("account", "secondPublicKey").c_str(),
		// parser->subarrayValueIn("account", 0, "multisignatures").c_str(),	//	FIXME
		// multisigsArray,																										//	FIXME
		// parser->subarrayValueIn("account", 0, "u_multisignatures").c_str()	//	FIXME
		// u_multisigsArray																										//	FIXME
	};
};
/*************************************************/
