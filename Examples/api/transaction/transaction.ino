#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";

/********************************************************************************
* transaction: 
********************************************************************************/

void checkAPI() {
  /*************************************************/
  ARK::Network devnet = ARK::Constants::Networks::Model::Devnet;
  ARK::API::Manager arkManager(devnet);
  /*************************************************/

  Hash transactionID("4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e");

  /*************************************************/
	auto transactionFromID = arkManager.transaction(transactionID);
    Serial.print("\ntransactionFromID: ");
    Serial.println(transactionFromID);
    delay(50);
  /*************************************************/

  /*************************************************/
  /*************************************************/
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~28,908 bytes  */
//  String transactions = _arkManager.transactions();
//    Serial.println("transactions: ");
//    Serial.println(transactions);
//    Serial.println("\n=====\n");
//    delay(50);
  /*************************************************/
  /*************************************************/

  /*************************************************/
	auto transactionUnconfirmedFromId = arkManager.transactionUnconfirmed(transactionID);
    Serial.print("\ntransactionUnconfirmedFromId: ");
    Serial.println(transactionUnconfirmedFromId);
    delay(50);
  /*************************************************/

  /*************************************************/
	auto transactionsUnconfirmed = arkManager.transactionsUnconfirmed();
    Serial.print("\ntransactionsUnconfirmed: ");
    Serial.println(transactionsUnconfirmed);
    delay(50);
  /*************************************************/
}

/*************************************************/
void setup()
{
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	Serial.println();

	Serial.print("Connected, IP address: ");
	Serial.println(WiFi.localIP());
  checkAPI();
}

void loop() {}
/*************************************************/
