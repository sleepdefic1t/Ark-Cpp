

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
* ARK::API::Block::Respondable::blocks_s 
**************************************************/
struct Blocks :
		public Printable
{
	private:
		size_t count_;
    	std::unique_ptr<ARK::Block[]> blocks_;

	public:
		Blocks(size_t newCapacity);

		size_t count() const;
		void setCount(int newCount);

		const ARK::Block &operator[](size_t index) const;
		ARK::Block &operator[](size_t index);

		virtual size_t printTo(Print &p) const;
};
/*************************************************/

/**************************************************************************************************/

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
		Height(
				const char *const newHeight,
				const char *const newID
		);

		const char* height() const noexcept { return height_; }
		const char* id() const noexcept { return id_; }

		virtual size_t printTo(Print &p) const;
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
		Status(
				const char *const newEpoch,
				const char *const newHeight,
				const char *const newFee,
				int newMilestone,
				const char *const newNethash,
				const char *const newReward,
				const char *const newSupply
		);

		const char* epoch() const noexcept { return epoch_; }
		const char* height() const noexcept { return height_; }
		const Balance& fee() const noexcept { return fee_; }
		int milestone() const noexcept { return milestone_; }
		const Hash nethash() const noexcept { return nethash_; }
		const Balance& reward() const noexcept { return reward_; }
		const Balance& supply() const noexcept { return supply_; }

		virtual size_t printTo(Print &p) const;		
};
/*************************************************/

};
};
};
};

#endif
