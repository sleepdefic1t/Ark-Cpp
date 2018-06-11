

#ifndef HASH_H
#define HASH_H

#include "utilities/platform.h"
#include "types/base/hexable.h"

/********************************************************************************
* hash: 
*	"578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23"
*	64 Characters | HEX-encoded
*	Size 256
********************************************************************************/

#define HASH_STORAGE_BYTE_COUNT 32
#define HASH_STRING_LENGTH 64

#define Hash Hexable<HASH_STORAGE_BYTE_COUNT>


#endif
