

#ifndef ECKEY_H
#define ECKEY_H

#include "utilities/platform.h"
#include "types/base/hexable.h"

/********************************************************************************
*	Privatekey: 
*	Elliptical Curve SECP256K1 Privatekey (essentially a SHA256 in this instance)
*	32 bytes
*	64 Characters
*	@brief Represents a 256-bit number
********************************************************************************/

#define PRIVKEY_STORAGE_BYTE_COUNT 32
#define PRIVKEY_STRING_LENGTH 64

#define Privatekey Hexable<PRIVKEY_STORAGE_BYTE_COUNT>


/********************************************************************************
*	Publickey: 
*	Elliptical Curve SECP256K1 Compressed Publickey
*	ex: "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"
*
*	33 bytes
*	66 Characters
*	@brief Represents a 257-bit number
********************************************************************************/

#define PUBKEY_STORAGE_BYTE_COUNT 33
#define PUBKEY_STRING_LENGTH 66

#define Publickey Hexable<PUBKEY_STORAGE_BYTE_COUNT>


#endif
