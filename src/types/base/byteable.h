

#ifndef BYTEABLE_H
#define BYTEABLE_H

#include "utilities/platform.h"
#include "utilities/formatting.h"
#include <vector>
#include <memory>

template <size_t COUNT>
class Byteable
{
    protected:
		uint8_t bytes_[COUNT];
	public:
		/************************************************** 
		* Constructor 
		* @brief: default empty constructor
		**************************************************/
		Byteable() : bytes_() {};
		/*************************************************/

		/************************************************** 
		* Constructor 
		* @brief: default constructor
        * @param: const uint8_t *const newBytes
		**************************************************/
		Byteable(const uint8_t *const newBytes)
		{ 
			(sizeof(newBytes) == COUNT)
				? std::memmove(this->bytes_, newBytes, COUNT)
				: void(this->bytes_[0] = '\0');
		};
		/*************************************************/

		/************************************************** 
		* Deconstructor 
		* @brief: fill this->bytes_ with random data before deconstruction
		**************************************************/
		~Byteable() { Sanitize(this->bytes_, COUNT); };
		/*************************************************/

		/************************************************** 
		* @brief: returns size of Byteable object
		**************************************************/
		size_t size() const
		{
			return (sizeof(this->bytes_) == COUNT)
					? COUNT
					: 0;
		};
		/*************************************************/

		/************************************************** 
		* @brief: returns vector of stored bytes
		**************************************************/
		const inline std::vector<uint8_t> vBytes() const
		{
			return std::vector<uint8_t>(this->bytes_);
		};
		/*************************************************/

};

#endif
