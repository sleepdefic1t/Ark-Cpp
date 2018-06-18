

#include "api/transactionable/transactionable.h"

/*************************************************
* /api/transactions/get?id=
*
* EXAMPLE:
* {
*  "success": true,
*  "transaction": {
*    "id": "4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e",
*	 "blockid": "14671461178414977683",
*    "height": 1696504,
*    "type": 0,
*    "timestamp": 19637685,
*    "amount": 149,
*    "fee": 10000000,
*    "vendorField": "1ARK-GOLang is saying whoop whooop",
*    "senderId": "DPJBH7wfE1msZMVDQLeJUPi31fJZodJCkU",
*    "recipientId": "DFTzLwEHKKn3VGce6vZSueEmoPWpEZswhB",
*    "senderPublicKey": "03a151b47a5779949a47dd9c17e05c832304721a242b535f36528cd7e547dac439",
*    "signature": "3045022100dc9590c6c6fce66a523481f13237d95518056387076de9a9534cb4a039fbede90220322e7f17b227f8fe9401460980b7b3c1baacf076b9020620ec5c4388673e7e12",
*    "confirmations": "1868079"
*  }
* }
**************************************************/
ARK::Transaction ARK::API::Transactionable::transaction(const Hash &id)
{
	char uri[114 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Transaction::getSingle_s);
		strcat(uri, "?id=");
		strcat(uri, id.c_str());
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return {
		parser->valueIn("transaction", "id").c_str(),
		parser->valueIn("transaction", "blockid").c_str(),
		parser->valueIn("transaction", "height").c_str(),
		convert_to_int(parser->valueIn("transaction", "type").c_str()),
		parser->valueIn("transaction", "timestamp").c_str(),
		parser->valueIn("transaction", "amount").c_str(),
		parser->valueIn("transaction", "fee").c_str(),
		parser->valueIn("transaction", "vendorField").c_str(),
		parser->valueIn("transaction", "senderId").c_str(),
		parser->valueIn("transaction", "recipientId").c_str(),
		parser->valueIn("transaction", "senderPublicKey").c_str(),
		parser->valueIn("transaction", "signature").c_str(),
		parser->valueIn("transaction", "confirmations").c_str()
	};
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/transactions/get?id=
*
* EXAMPLE:
* {
*  "success": true,
*  "transactions":
*	[
*		{
*			"id": "string",
*			"blockid": "string",
*			"height": int,
*			"type": ing,
*			"timestamp": ing,
*			"amount": Balance,
*			"fee": Balance,
*			"vendorField": "string",
*			"senderId": "Address",
*			"recipientId": "Address",
*			"senderPublicKey": "Publickey",
*			"signature": "Signature",
*			"confirmations": "string"
*		},
*		...
*		{
*			"id": "string",
*			"blockid": "string",
*			"height": int,
*			"type": ing,
*			"timestamp": ing,
*			"amount": Balance,
*			"fee": Balance,
*			"vendorField": "string",
*			"senderId": "Address",
*			"recipientId": "Address",
*			"senderPublicKey": "Publickey",
*			"signature": "Signature",
*			"confirmations": "string"
*		}
*	]
*	"count": "int"
* }
**************************************************/
ARK::API::Transaction::Respondable::Transactions ARK::API::Transactionable::transactions()
{
	char uri[69] = { '\0' };
		strcpy(uri, ARK::API::Paths::Transaction::transactions_s);
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);

	const size_t maxCapacity = 20; // limit to 20 peers
	ARK::API::Transaction::Respondable::Transactions transactions(maxCapacity);

	for (int i = 0; i < maxCapacity; i++)
	{
		transactions[i] = {
		parser->subarrayValueIn("transactions", i, "id").c_str(),
		parser->subarrayValueIn("transactions", i, "blockid").c_str(),
		parser->subarrayValueIn("transactions", i, "height").c_str(),
		convert_to_int(parser->subarrayValueIn("transactions", i, "type").c_str()),
		parser->subarrayValueIn("transactions", i, "timestamp").c_str(),
		parser->subarrayValueIn("transactions", i, "amount").c_str(),
		parser->subarrayValueIn("transactions", i, "fee").c_str(),
		parser->subarrayValueIn("transactions", i, "vendorField").c_str(),
		parser->subarrayValueIn("transactions", i, "senderId").c_str(),
		parser->subarrayValueIn("transactions", i, "recipientId").c_str(),
		parser->subarrayValueIn("transactions", i, "senderPublicKey").c_str(),
		parser->subarrayValueIn("transactions", i, "signature").c_str(),
		parser->subarrayValueIn("transactions", i, "confirmations").c_str()
		};
	};
	transactions.setCount( convert_to_int(parser->valueFor("count").c_str()));
	return transactions;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/transactions/unconfirmed/get?id=
*
* EXAMPLE:
* { 
*	"success":true,
*	"transaction":
*	{
*		"id": Hash,
*		"blockid":"_blockID",
*		"height":_height,
*		"type":_type,
*		"timestamp":_timestamp,
*		"amount":_amount,
*		"fee":_fee,
*		"vendorField":_vendorField,
*		"senderId":"_senderId",
*		"recipientId":"_recipientId",
*		"senderPublicKey":_senderPubkey,
*		"signature":"_txSig",
*		"confirmations":_confirmations
*	}
* }
*	| or |
* {
*	"success":false,
*	"error":"Transaction not found"
* }
**************************************************/
ARK::API::Transaction::Respondable::Unconfirmed ARK::API::Transactionable::transactionUnconfirmed(const Hash &id)
{
	char uri[126 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Transaction::getSingleUnconfirmed_s);
		strcat(uri, "?id=");
		strcat(uri, id.c_str());
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);
	int txCount = substringCount(callback.c_str(), "id");
	std::unique_ptr<ARK::Transaction[]> transactions(new ARK::Transaction[txCount]);
	for (int i = 0; i < txCount; i++)
	{
		transactions[i] = ARK::Transaction(
			parser->valueIn("transaction", "id").c_str(),
			parser->valueIn("transaction", "blockid").c_str(),
			parser->valueIn("transaction", "height").c_str(),
			convert_to_int(parser->valueIn("transaction", "type").c_str()),
			parser->valueIn("transaction", "timestamp").c_str(),
			parser->valueIn("transaction", "amount").c_str(),
			parser->valueIn("transaction", "fee").c_str(),
			parser->valueIn("transaction", "vendorField").c_str(),
			parser->valueIn("transaction", "senderId").c_str(),
			parser->valueIn("transaction", "recipientId").c_str(),
			parser->valueIn("transaction", "senderPublicKey").c_str(),
			parser->valueIn("transaction", "signature").c_str(),
			parser->valueIn("transaction", "confirmations").c_str()
		);
	};
	return ARK::API::Transaction::Respondable::Unconfirmed(transactions.get(), txCount);
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/transactions/unconfirmed
*
* EXAMPLE:
* {
*	"success":true,
*	"transactions":[]
* }
**************************************************/
ARK::API::Transaction::Respondable::Unconfirmed ARK::API::Transactionable::transactionsUnconfirmed()
{
	auto callback = netConnector.callback(ARK::API::Paths::Transaction::unconfirmed_s);
	auto parser = ARK::Utilities::makeJSONString(callback);
	int txCount = substringCount(callback.c_str(), "id");
	std::unique_ptr<ARK::Transaction[]> transactions(new ARK::Transaction[txCount]);
	for (int i = 0; i < txCount; ++i)
	{
		transactions[i] = ARK::Transaction(
			parser->valueIn("transaction", "id").c_str(),
			parser->valueIn("transaction", "blockid").c_str(),
			parser->valueIn("transaction", "height").c_str(),
			convert_to_int(parser->valueIn("transaction", "type").c_str()),
			parser->valueIn("transaction", "timestamp").c_str(),
			parser->valueIn("transaction", "amount").c_str(),
			parser->valueIn("transaction", "fee").c_str(),
			parser->valueIn("transaction", "vendorField").c_str(),
			parser->valueIn("transaction", "senderId").c_str(),
			parser->valueIn("transaction", "recipientId").c_str(),
			parser->valueIn("transaction", "senderPublicKey").c_str(),
			parser->valueIn("transaction", "signature").c_str(),
			parser->valueIn("transaction", "confirmations").c_str()
		);
	};
	return { transactions.get(), txCount };
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* /api/transactions/get?id=
*
* @brief: Gets vendorField for a given Transaction by  txID from a Node via API.
**************************************************/
const char *ARK::API::Transactionable::getVendorField(const Hash &txID)
{
	char uri[114 + 1] = { '\0' };
		strcpy(uri, ARK::API::Paths::Transaction::getSingle_s);
		strcat(uri, "?id=");
		strcat(uri, txID.c_str());
	auto callback = netConnector.callback(uri);
	auto parser = ARK::Utilities::makeJSONString(callback);
	return parser->valueIn("transaction", "vendorField").c_str();
};
/*************************************************/
