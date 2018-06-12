

#ifndef HEXABLE_H
#define HEXABLE_H

#include "utilities/platform.h"
#include "utilities/formatting.h"
#include "types/base/byteable.h"
#include <vector>
#include <memory>

template <size_t COUNT>
class Hexable :
		public Printable,
		virtual Byteable<COUNT>
{
	public:
		/************************************************** 
		* Constructor 
		* @brief: default empty constructor
		**************************************************/
		Hexable() { this->bytes_[0] = '\0'; };
		/*************************************************/
		
		/************************************************** 
		* Constructor 
		* @param: const char *const newHash
		* @brief: also checks if Hash is empty before storage
		**************************************************/
		Hexable(const char *const newValue)
		{ 
			(isHex(newValue))
				? void(
					std::memmove(
						this->bytes_,
						&ParseHex(newValue).data()[0],
						COUNT
					)
				)
				: void(this->bytes_[0] = '\0');
		};
		/*************************************************/

		/************************************************** 
		* @brief: returns vector of hex-string representation of stored bytes
		**************************************************/
		const inline std::vector<char> vHex() const
		{
			return (this->bytes_[0] != '\0')
				? std::vector<char>(this->hex().c_str())
				: std::vector<char>(1);
		};
		/*************************************************/

		/**************************************************
		* @brief: return hex-cstring of Hexable type
		**************************************************/
		const char* c_str() const
		{
			return (this->bytes_[0] != '\0')
				? BytesToHex(this->bytes_, this->bytes_ + COUNT).c_str()
				: std::string("").c_str();
		};

		/**************************************************
		* @param: Print& p 
		* @brief: prints Hexable object
		**************************************************/
		virtual size_t printTo(Print& p) const
		{
			size_t size = 0;
			size += p.print( this->c_str() );
			return size;
		};
		/*************************************************/

};

#endif
