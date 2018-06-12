#include <ark.h>

/********************************************************************************
*
* address: 
*   "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA"
*   
*   34 Characters | Base58-encoded
*
********************************************************************************/
void constructAddress()
{
  Address address("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");
    Serial.println("address: DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA\n");
    Serial.print("\naddress: ");
    Serial.println(address.c_str());
};

void setup()
{
  Serial.begin(115200);
  constructAddress();
}

void loop() {}
