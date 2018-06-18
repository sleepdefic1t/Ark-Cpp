

#include "api/blockable/block_respondable.h"

namespace ARK
{
namespace API
{
namespace Block
{
namespace Respondable
{
/*************************************************
* Blocks
**************************************************/
Blocks::Blocks(size_t newCapacity) :
		count_(),
		blocks_(new ARK::Block[newCapacity]) {}

size_t ARK::API::Block::Respondable::Blocks::count() const { return this->count_; }
void ARK::API::Block::Respondable::Blocks::setCount(int newCount) { this->count_ = newCount; }

const ARK::Block &ARK::API::Block::Respondable::Blocks::operator[](size_t index) const { return this->blocks_[index]; }
ARK::Block &ARK::API::Block::Respondable::Blocks::operator[](size_t index) { return this->blocks_[index]; }

size_t ARK::API::Block::Respondable::Blocks::printTo(Print &p) const
{
	size_t size = 0;
	if (this->count_ > 0)
	{
		size += p.print("\n\0");
		for (int i = 0; i < static_cast<int>(this->count_); i++)
		{
			size += p.print("\nblock ");
			size += p.print(i + 1);
			size += p.print(":\n");
			size += p.println(blocks_[i].printTo(p));
		};
		size += p.print("\ncount: ");
		size += p.print(this->count());
	};
	return size;
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* Constructor
**************************************************/
Height::Height(
		const char *const newHeight,
		const char *const newID
) {
	strncpy(this->height_, newHeight, sizeof(height_) / sizeof(height_[0]));
	strncpy(this->id_, newID, sizeof(id_) / sizeof(id_[0]));
}
/*************************************************/

/*************************************************
*
**************************************************/
size_t Height::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("\nheight: ");
		size += p.print(this->height_);
		size += p.print("\nid: ");
		size += p.print(this->id_);
	return size;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* Constructor
**************************************************/
Status::Status(
		const char *const newEpoch,
		const char *const newHeight,
		const char *const newFee,
		int newMilestone,
		const char *const newNethash,
		const char *const newReward,
		const char *const newSupply
)	:	fee_(newFee),
		milestone_(newMilestone),
		nethash_(newNethash),
		reward_(newReward),
		supply_(newSupply)
{
	strncpy(this->epoch_, newEpoch, sizeof(epoch_) / sizeof(epoch_[0]));
	strncpy(this->height_, newHeight, sizeof(height_) / sizeof(height_[0]));
};
/*************************************************/

/*************************************************
*
**************************************************/
size_t Status::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("\nepoch: ");
		size += p.print(this->epoch_);

		size += p.print("\nheight: ");
		size += p.print(this->height_);

		size += p.print("\nfee: ");
		size += p.print(this->fee_.ark());

		size += p.print("\nmilestone: ");
		size += p.print(this->milestone_);

		size += p.print("\nnethash: ");
		size += p.print(this->nethash_.c_str());

		size += p.print("\nreward: ");
		size += p.print(this->reward_.ark());

		size += p.print("\nsupply: ");
		size += p.print(this->supply_.ark());
  return size;
};
/*************************************************/

};
};
};
};
