

#ifndef BLOCK_RESPONDABLE_H
#define BLOCK_RESPONDABLE_H

#include "utilities/platform.h"
#include "types/balance.h"
#include "types/hash.h"
#include "models/block.h"
#include <cstring>
#include <cstdio>

namespace ARK
{
namespace API
{
namespace Block
{
namespace Respondable
{
/*************************************************
* ARK::API::Block::Respondable::height_t 
*
* @param: char height[64]
* @param: char id[64]
*
* @brief: Model for Height API Response
**************************************************/
struct Height :
		public Printable
{
	protected:
		char height_[64];
		char id_[64];
		
	public:
		/*************************************************
		* Constructor
		**************************************************/
		Height(
				const char *const newHeight,
				const char *const newID
		);
		/*************************************************/

		/*************************************************
		* Accessors
		**************************************************/
		const char* height() const noexcept { return height_; }
		const char* id() const noexcept { return id_; }
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print &p) const;
		/*************************************************/

};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Block::Respondable::Status 
*
* @param: const char* epoch
* @param: const char* height
* @param: const Balance fee
* @param: int milestone
* @param: Hash nethash
* @param: const Balance reward
* @param: const Balance supply
*
* @brief: Model for Block Status API Response
**************************************************/
struct Status :
		public Printable
{

	protected:
		char epoch_[64]; //TODO: check sizes
		char height_[64];
		Balance fee_;
		int milestone_;
		Hash nethash_;
		Balance reward_;
		Balance supply_;
	public:
		/*************************************************
		* Constructor
		**************************************************/
		Status(
				const char *const newEpoch,
				const char *const newHeight,
				const char *const newFee,
				int newMilestone,
				const char *const newNethash,
				const char *const newReward,
				const char *const newSupply
		);
		/*************************************************/

		/*************************************************
		* Accessors
		**************************************************/
		const char* epoch() const noexcept { return epoch_; }
		const char* height() const noexcept { return height_; }
		const Balance& fee() const noexcept { return fee_; }
		int milestone() const noexcept { return milestone_; }
		const Hash nethash() const noexcept { return nethash_; }
		const Balance& reward() const noexcept { return reward_; }
		const Balance& supply() const noexcept { return supply_; }
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print &p) const;
		/*************************************************/
		
};
/*************************************************/

};
};
};
};

#endif

// 60k callback too big for arduino. maybe implement a stream parser?
/**************************************************************************************************/
/*************************************************
* ARK::API::Block::Respondable::blocks_s 
*
* @param: char height[64]
* @param: char id[64]
*
* @brief: Model for Height API Response
**************************************************/
// struct Blocks :
// 		public Printable
// {
// 	private:
// 		size_t capacity_;
// 		unsigned int count_;
//     	std::unique_ptr<ARK::Block[]> blocks_;

// 	public:
// 		Blocks(size_t capacity, unsigned int newBlockCount);
// 		size_t capacity() const;
// 		unsigned int count() const;
// 		const ARK::Block &operator[](size_t index) const;
// 		ARK::Block &operator[](size_t index);
// 		virtual size_t printTo(Print &p) const;
// };
/*************************************************/
/**************************************************************************************************/
/*************************************************/
// Blocks::Blocks(size_t capacity, unsigned int newBlockCount) :
// 		capacity_(capacity),
// 		blocks_(new ARK::Block[capacity]),
// 		count_(newBlockCount) {}
// const ARK::Block &ARK::API::Block::Respondable::Blocks::operator[](size_t index) const { return this->blocks_[index]; }
// ARK::Block &ARK::API::Block::Respondable::Blocks::operator[](size_t index) { return this->blocks_[index]; }
// size_t ARK::API::Block::Respondable::Blocks::capacity() const { return this->capacity_; }
// unsigned int ARK::API::Block::Respondable::Blocks::count() const { return this->count_; };
// size_t ARK::API::Block::Respondable::Blocks::printTo(Print &p) const
// {
// 	size_t size = 0;
// 	if (this->count_ > 0)
// 	{
// 		size += p.print("\n\0");
// 		for (int i = 0; i < static_cast<int>(this->count_); i++)
// 		{
// 			size += p.print("\nblock ");
// 			size += p.print(i + 1);
// 			size += p.print(":\n");
// 			size += p.println(blocks_[i].printTo(p));
// 		};
// 	};
// 	return size;
// }
/*************************************************/
/**************************************************************************************************/