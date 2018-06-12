#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";

/********************************************************************************
* delegate: 
********************************************************************************/

void checkAPI() {
  /*************************************************/
  ARK::Network devnet = ARK::Constants::Networks::Model::Devnet;
  ARK::API::Manager arkManager(devnet);
  /*************************************************/

  Publickey darkPubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");

  /*************************************************/
  const int delegatesCount = arkManager.delegatesCount();
    Serial.printl(\n"delegatesCount: ");
    Serial.println(delegatesCount);
    delay(50);
  /*************************************************/

  /*************************************************/
  auto delegateSearch = arkManager.delegateSearch("sleepdeficit");
    Serial.print("\ndelegateSearch: ");
    Serial.println(delegateSearch);
    delay(50);
  /*************************************************/

  /*************************************************/
  auto delegateVoters = arkManager.delegateVoters(darkPubkey);
    Serial.print("\ndelegateVoters: ");
    Serial.println(delegateVoters);
    delay(50);
  /*************************************************/

  /*************************************************/
  ARK::Delegate delegateByUsername = arkManager.delegate("sleepdeficit");
    Serial.print("\ndelegateByUsername: ");
    Serial.println(delegateByUsername);
    delay(50);
  /*************************************************/

  /*************************************************/
  ARK::Delegate delegateByPublickey = arkManager.delegate(darkPubkey);
    Serial.print("\ndelegateByPublickey: ");
    Serial.println(delegateByPublickey.c_str());
    delay(50);
  /*************************************************/

  /*************************************************/
  /*************************************************/
/*    BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
//  String delegates = _arkManager.getDelegates();
//    Serial.println("delegates: ");
//    Serial.println(delegates);
//    Serial.println("\n=====\n");
//    delay(50);
  /*************************************************/
  /*************************************************/

  /*************************************************/
	Balance delegateFee = arkManager.delegateFee();
    Serial.print("\ndelegateFee: ");
    Serial.println(delegateFee.ark());
    delay(50);
  /*************************************************/

  /*************************************************/
  auto delegateForgedByAccount = arkManager.delegateForgedByAccount(darkPubkey);
    Serial.print("\ndelegateForgedByAccount: ");
    Serial.println(delegateForgedByAccount);
    delay(50);
  /*************************************************/

  /*************************************************/
  auto delegateNextForgers = arkManager.delegateNextForgers();
    Serial.print("\ndelegateNextForgers: ");
    Serial.println(delegateNextForgers);
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
