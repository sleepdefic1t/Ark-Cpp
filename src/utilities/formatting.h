


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

static void BytesToHex(const uint8_t *newBytes, char* hex, size_t byteCount)
{
	for (size_t i = 0; i < byteCount; i++)
	{
		sprintf(&hex[2*i], "%02x", newBytes[i]);
	};
};

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
