


#ifndef FORMATTING_H
#define FORMATTING_H

#include "utilities/platform.h"
#include <memory>
#include <vector>

/**
 fill buffer with random data before deleting char/uint8_t array
**/
// void Sanitize(char* buffer, size_t size)
// {
// 	for (int i = 0; i < size; i++)
// 	{
// 		std::default_random_engine generator;
// 		std::uniform_int_distribution<uint32_t> distribution(0, 255);
// 		buffer[i] = distribution(generator);
// 	};
// };

static uint8_t getRandomDigit()
{	
#ifdef USE_IOT
	randomSeed(random(0, 1024));
	return random(0, 255);
#else
	std::default_random_engine generator;
	std::uniform_int_distribution<uint32_t> distribution(0, 255);
	return distribution(generator);
#endif
}

static void Sanitize(uint8_t* buffer, size_t size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		buffer[i] = getRandomDigit();
	};
};
/**/




static bool isHex(const char *const newHash)
{
	for (unsigned int i = 0; i < sizeof(newHash); i++)
	{
		if ( !std::isxdigit(newHash[i]) ) { return false; };
	};
	return true;
};


template<typename T>
static std::string BytesToHex(const T itbegin, const T itend, bool fSpaces = false)
{
	std::string rv;
	static const char hexmap[16] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'
	};
	rv.reserve((itend - itbegin) * 3);
	for (T it = itbegin; it < itend; ++it)
	{
		unsigned char val = (unsigned char)(*it);
		if (fSpaces && it != itbegin)
			rv.push_back(' ');
		rv.push_back(hexmap[val >> 4]);
		rv.push_back(hexmap[val & 15]);
	}

	return rv;
}

template<typename T>
static inline std::string BytesToHex(const T& vch, bool fSpaces = false)
{
	return BytesToHex(vch.begin(), vch.end(), fSpaces);
}




static const signed char p_util_hexdigit[256] =
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
0,1,2,3,4,5,6,7,8,9,-1,-1,-1,-1,-1,-1,
-1,0xa,0xb,0xc,0xd,0xe,0xf,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,0xa,0xb,0xc,0xd,0xe,0xf,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, };

static signed char HexDigit(char c)
{
	return p_util_hexdigit[(unsigned char)c];
}

static std::vector<unsigned char> ParseHex(const char* psz)
{
	// convert hex dump to vector
	std::vector<unsigned char> vch;
	while (true)
	{
		while (isspace(*psz))
			psz++;
		signed char c = HexDigit(*psz++);
		if (c == (signed char)-1)
			break;
		unsigned char n = (c << 4);
		c = HexDigit(*psz++);
		if (c == (signed char)-1)
			break;
		n |= c;
		vch.push_back(n);
	}
	return vch;
}

static std::vector<unsigned char> ParseHex(const std::string& str)
{
	return ParseHex(str.c_str());
}

static void HexToBytes(const char *const hex, uint8_t *bytes)
{
	size_t len = strlen(hex);
	char buffer[3];
	buffer[2] = 0;
	int length = len;
	for (int i = 0; i < length - 1; i += 2)
	{
		buffer[0] = hex[i];
		buffer[1] = hex[i + 1];
		bytes[i/2] = (char)strtoul(buffer, NULL, 16);
	}
};

#endif
