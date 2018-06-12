#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";

/********************************************************************************
* account: 
********************************************************************************/

void checkAPI() {
  /*************************************************/
  ARK::Network devnet = ARK::Constants::Networks::Model::Devnet;
  ARK::API::Manager arkManager(devnet);
  /*************************************************/
  
  Address darkAddress("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");

  /*************************************************/
  auto balances = arkManager.accountBalance(darkAddress);
    Serial.print("\nbalanceDescription: ");
    Serial.println(balances);
    delay(50); 
  /*************************************************/

  /*************************************************/
  auto publicKey = arkManager.accountPublickey(darkAddress);
    Serial.print(\n"publicKey: ");
    Serial.println(publicKey.c_str());
    delay(50);
  /*************************************************/

  /*************************************************/
  Balance delegatesFee = arkManager.accountDelegatesFee(darkAddress);
    Serial.print("\ndelegatesFee: ");
    Serial.println(delegatesFee.ark());
    delay(50);
  /*************************************************/
  
  /*************************************************/
  ARK::Delegate delegate = arkManager.accountDelegates(darkAddress);
    Serial.print("\ndelegate: ");
    Serial.println(delegate);
  delay(50);
  /*************************************************/

  /*************************************************/
  auto account = arkManager.account(darkAddress);
    Serial.print("\naccount: ");
    Serial.println(account);
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
