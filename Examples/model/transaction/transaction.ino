#include <ark.h>

/********************************************************************************
*
*{
*  "success": true,
*  "transaction": {
*    "id": "4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e",
*    "blockid": "14671461178414977683",
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
*}
*
********************************************************************************/
void constructTransaction()
{
  ARK::Transaction transaction(
    "f93b1b635eaaeea21b26ebf1e10f62dc8874add6592737a1540d28ec9432eaa9",
    "14671461178414977683",
    "1696504",
    0,
    "9656006",
    "51000",
    "10000000",
    "vendorField",
    "DAYS6o9sA51kMCSaSP216GZ8pomGkRsQiR",
    "D7FyqZohN83vxQdqUjJWqD2CPQBxhut9WD",
    "039b5a3a71335bfa6c72b82498f814123e0678f7cd3d8e7221ec7124918736e01c",
    "3045022100f632a89be97cb928cef6358b1a6c0e5b44381288ffe3f977768052c39f44c31102200cdfb289240ba03628d6b487d3869881de981322a8826bb5749704e6f6baa63b",
    0
  );
  Serial.print("\nOffline Instantiated Transaction Description\n"); 
  Serial.println(transaction); 
};

void setup()
{
  Serial.begin(115200);
  constructTransaction();
}

void loop() {}
