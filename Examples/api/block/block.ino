#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";

/********************************************************************************
* block: 
********************************************************************************/

void checkAPI() {
  /*************************************************/
  ARK::Network devnet = ARK::Constants::Networks::Model::Devnet;
  ARK::API::Manager arkManager(devnet);
  /*************************************************/

  /*************************************************/
  ARK::Block block = arkManager.block("4367122150875693402");
    Serial.print("\nblock: ");
    Serial.println(block);
    delay(50);
  /*************************************************/


  /*************************************************/
  /*************************************************/
/* needs stream->string size fix for large callbacks */
//  String blocks = arkManager.blocks();
//    Serial.println(blocks);
//    Serial.println();
//    delay(50);
  /*************************************************/
  /*************************************************/


  /*************************************************/
  auto blockEpoch = arkManager.blockEpoch();
    Serial.print("\nblockEpoch: ");
    Serial.println(blockEpoch);
    delay(50);
  /*************************************************/

  /*************************************************/
  auto blockHeight =  arkManager.blockHeight();
    Serial.print("\nblockHeight: ");
    Serial.println(blockHeight);
    delay(50);
  /*************************************************/

  /*************************************************/
  Hash blockNethash = arkManager.blockNethash();
    Serial.print("\nblockNethash: ");
    Serial.println(blockNethash.c_str());
    delay(50);
  /*************************************************/

  /*************************************************/
  Balance blockFee = arkManager.blockFee();
    Serial.print("\nblockFee: ");
    Serial.println(blockFee.ark());
    delay(100);
  /*************************************************/

  /*************************************************/
  ARK::Fees blockFees = arkManager.blockFees();
    Serial.print("\nblockFees: ");
    Serial.println(blockFees);
    delay(100);
  /*************************************************/

  /*************************************************/
  auto blockMilestone = arkManager.blockMilestone();
    Serial.print("\nblockMilestone: ");
    Serial.println(blockMilestone);
    delay(50);
  /*************************************************/

  /*************************************************/
  Balance blockReward = arkManager.blockReward();
    Serial.print("\nblockReward: ");
    Serial.println(blockReward.ark());
    delay(50);
  /*************************************************/

  /*************************************************/
  Balance blockSupply = arkManager.blockSupply();
    Serial.print("\nblockSupply: ");
    Serial.println(blockSupply.ark());
    delay(50);
  /*************************************************/

  /*************************************************/
  auto blockStatus = arkManager.blockStatus();
    Serial.print("\nblockStatus: ");
    Serial.println(blockStatus);
    delay(50);
  /*************************************************/
}
/*************************************************/

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
