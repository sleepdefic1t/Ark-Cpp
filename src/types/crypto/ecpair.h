

#ifndef ECPAIR_H
#define ECPAIR_H

#include "utilities/platform.h"
#include "types/crypto/eckey.h"

/********************************************************************************
*	ECPair: 
*	Elliptical Curve SECP256K1 Privatekey Publickey pair
********************************************************************************/
struct ECPair
{
	const Privatekey d;
	const Publickey Q;
};

#endif
