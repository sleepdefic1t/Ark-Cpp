

#ifndef HASHABLE_H
#define HASHABLE_H

#include "utilities/platform.h"
#include "utilities/formatting.h"
#include <vector>
#include <memory>

template <size_t COUNT>
class Hashable :
		public Printable
{
	public:
		/************************************************** 
		*	Constructor 
		* @brief: default empty constructor
		**************************************************/
		Hashable() : bytes_() {};
		/*************************************************/

		/************************************************** 
		*	Constructor 
		*	@param: const char *const newHash
		* @brief: also checks if Hash is empty before storage
		**************************************************/
		Hashable(const char *const newHash)
		{ 
			strlen(newHash) != 0 ?
					this->set(newHash) :
					void(this->bytes_[0] = '\0');
		};
		/*************************************************/

		/************************************************** 
		*	Deconstructor 
		* @brief: fill this->bytes_ with random data before deconstruction
		**************************************************/
		~Hashable() {
			Sanitize(this->bytes_, COUNT);
		};
		/*************************************************/

		/************************************************** 
		* @brief: returns element count of Hashable object
		**************************************************/
		size_t count() const { return COUNT; };
		/*************************************************/

		/************************************************** 
		* @brief: returns size of Hashable object
		**************************************************/
		size_t size() const { return sizeof(this->bytes_); };
		/*************************************************/

		/************************************************** 
		* @brief: returns vector of stored bytes
		**************************************************/
		const inline std::vector<uint8_t> vBytes() const
		{
			return std::vector<uint8_t>(this->bytes_);
		};
		/*************************************************/

		/************************************************** 
		* @brief: returns vector of hex-string representation of stored bytes
		**************************************************/
		const inline std::vector<char> vHex() const
		{
			return (this->bytes_[0] != '\0') ?
					std::vector<char>(this->hex().c_str()) :
					std::vector<char>(1);
		};
		/*************************************************/

		/************************************************** 
		* @brief: returns hex-string representation of stored bytes
		**************************************************/
		std::string hex() const
		{
			if (this->bytes_[0] != '\0')
			{
				char hexBuffer[(COUNT * 2) + 1];
				BytesToHex(this->bytes_, hexBuffer, COUNT);
				return std::string( hexBuffer );
			}
			else
			{
				return std::string("");
			};
		}
		/*************************************************/

		/************************************************** 
		* @brief: returns hex c-string ('\0' or NULL Terminated string) representation of stored bytes
		**************************************************/
		operator const char *() const
		{
			return this->hex().c_str();
		};
		/*************************************************/

		/**************************************************
		* @param: Print& p 
		* @brief: prints Hashable object
		**************************************************/
		virtual size_t printTo(Print& p) const
		{
			size_t size = 0;
			size += p.print( this->hex().c_str() );
			return size;
		};
		/*************************************************/

	protected:
		uint8_t bytes_[COUNT];

		/**************************************************
		* @param: const char *const newHash 
		* @brief: Sets new Hash, copying byte-values to internal storage
		**************************************************/
		void set(const char *const newHash)
		{
			if (isHex(newHash))
			{ 
				HexToBytes(newHash, this->bytes_);
			}
			else
			{ 
				std::memmove(this->bytes_, newHash, COUNT);
			};
		};
		/*************************************************/

};

#endif
