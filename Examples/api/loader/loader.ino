#include <ark.h>
#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";

/********************************************************************************
* loader: 
********************************************************************************/

void checkAPI() {
  /*************************************************/
  ARK::Network devnet = ARK::Constants::Networks::Model::Devnet;
  ARK::API::Manager arkManager(devnet);
  /*************************************************/

  /*************************************************/
	auto loaderStatus = arkManager.loaderStatus();
    Serial.print("\nloaderStatus: ");
    Serial.println(loaderStatus);
    delay(50);
  /*************************************************/

  /*************************************************/
	auto loaderSync = arkManager.loaderSync();
    Serial.print("\nloaderSync: ");
    Serial.println(loaderSync);
    delay(50);
  /*************************************************/

  /*************************************************/
	auto autoconfigure = arkManager.loaderAutoconfigure();
    Serial.print("\nautoconfigure: ");
    Serial.println(autoconfigure);
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
