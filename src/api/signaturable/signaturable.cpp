

#include "api/signaturable/signaturable.h"

/*************************************************
* /api/signatures/fee
*
* EXAMPLE:
* {
*   "success":true,
*   "fee":  Balance
* }	
**************************************************/
Balance ARK::API::Signaturable::signaturesFee()
{
    auto callback = netConnector.callback(ARK::API::Paths::Signatures::fee_s);
    auto parser = ARK::Utilities::makeJSONString(callback);
    return Balance(parser->valueFor("fee").c_str());
};
/*************************************************/
