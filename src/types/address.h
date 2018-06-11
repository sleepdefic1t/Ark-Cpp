

#ifndef ADDRESS_H
#define ADDRESS_H

#include "utilities/platform.h"
#include "utilities/formatting.h"
#include "types/base/byteable.h"
#include <cstring>
#include <memory>

/*******************************************************************************
* address: 
*	"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA"
*   
*	34 Characters | Base58-encoded
*	Size 272
*	160-bit base58Encoded hash from a RIPEME160 hash
********************************************************************************/
#define ADDRESS_LENGTH 34		/* Actual Length of Address */
/*************************************************
*	Address
**************************************************/
class Address :
		public Printable,
		virtual Byteable<ADDRESS_LENGTH>
{
	public:
		/************************************************** 
		* Constructor 
		* @brief: default empty constructor
		**************************************************/
		Address() {};
		/*************************************************/

		/************************************************** 
		* Constructor 
		* @brief: default constructor
		* @param: const char *const newValue
		**************************************************/
		Address(const char *const newValue)
		{ 
			(strlen(newValue) == ADDRESS_LENGTH)
				? void(std::memmove(this->bytes_, newValue, ADDRESS_LENGTH))
				: void(this->bytes_[0] = { '\0' });
		};
		/*************************************************/

		/************************************************** 
		* @brief: returns cstring representation of stored bytes
		**************************************************/
		const char *getValue() const
		{
			return std::string(
				this->bytes_,
				this->bytes_ + ADDRESS_LENGTH
			).c_str();
		};
		/*************************************************/

		/************************************************** 
		* @brief: returns hex c-string ('\0' or NULL Terminated string) representation of stored bytes
		**************************************************/
		operator const char *() const { return this->getValue(); };
		/*************************************************/

		/**************************************************
		* @param: Print& p 
		* @brief: prints Address object
		**************************************************/
		virtual size_t printTo(Print& p) const
		{
			size_t size = 0;
			for (int i = 0; i < ADDRESS_LENGTH; i++)
			{
				size += p.print( this->bytes_[i] );
			};
			return size;
		};
		/*************************************************/

};

#endif
