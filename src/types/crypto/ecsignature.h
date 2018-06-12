

#ifndef ECSIGNATURE_H
#define ECSIGNATURE_H

#include "utilities/platform.h"
#include "types/base/hexable.h"

/********************************************************************************
* Signature: 
* Elliptical Curve SECP256K1 Signature
* ex: "3045022100e0fc6b066209fd9a70e61372cda2e38431ace5cf79ee0557eb2b1b14315d70f302201978696b71c9a177fa1ce9480ceb1ad04a15471d4c6e8d5b2dcd6d931f350efe"
*
* 71 bytes
* 142 Characters
********************************************************************************/

#define SIGNATURE_BYTE_COUNT 71
#define SIGNATURE_STRING_LENGTH 142

#define Signature Hexable<SIGNATURE_BYTE_COUNT>


#endif
