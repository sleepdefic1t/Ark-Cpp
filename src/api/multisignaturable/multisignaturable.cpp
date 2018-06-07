

#include "api/multisignaturable/multisignaturable.h"

/*************************************************
*	/api/multisignatures/pending?publicKey=
*
*	EXAMPLE:
*	{
*		"success":true,
*		"transactions":[]
*	}
**************************************************/
const char *ARK::API::MultiSignaturable::multisignaturesPending(
        const Publickey &publicKey
)
{
    char uri[130 + 1] = { '\0' };
        strcpy(uri, ARK::API::Paths::MultiSignatures::pending_s);
        strcat(uri, "?publicKey=");
        strcat(uri, publicKey);
    auto callback = netConnector.callback(uri);
    auto parser = ARK::Utilities::make_json_string(callback);
    return parser->valueFor("transactions").c_str();
};
/*************************************************/
