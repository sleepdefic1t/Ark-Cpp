

#include "api/transactionable/transaction_respondable.h"

namespace ARK
{
namespace API
{
namespace Transaction
{
namespace Respondable 
{
/*************************************************
* Peers
**************************************************/
Transactions::Transactions(size_t newCapacity) :
		transactions_(new ARK::Transaction[newCapacity]) {}

size_t ARK::API::Transaction::Respondable::Transactions::count() const { return this->count_; }
void ARK::API::Transaction::Respondable::Transactions::setCount(int newCount) { this->count_ = newCount; }

const ARK::Transaction &ARK::API::Transaction::Respondable::Transactions::operator[](size_t index) const { return this->transactions_[index]; }
ARK::Transaction &ARK::API::Transaction::Respondable::Transactions::operator[](size_t index) { return this->transactions_[index]; }

size_t ARK::API::Transaction::Respondable::Transactions::printTo(Print &p) const
{
	size_t size = 0;
	size += p.print("\n\0");
	for (int i = 0; i < 20; i++)
	{
		size += p.print("\ntransactions: ");
		size += p.print(i + 1);
		size += p.print(":\n");
		size += p.println(this->transactions_[i].printTo(p));
	};
	size += p.print("\ncount: ");
	size += p.print(this->count());
	return size;
}
/*************************************************/

/**************************************************************************************************/

/*************************************************
* Constructor
**************************************************/
Unconfirmed::Unconfirmed(
		const ARK::Transaction* const newTx,
		int newCount
)	:	count_(newCount)
{
	assert((unsigned int)this->count_ <= transactions_.size());
	for (int i = 0u; i < this->count_; ++i)
	{
		this->transactions_[i] = newTx[i];
	}
}
/*************************************************/

// /*************************************************
// * Deconstructor
// **************************************************/
// Unconfirmed::~Unconfirmed() { delete[] transactions_; }
// /*************************************************/

/*************************************************
*
**************************************************/
size_t Unconfirmed::printTo(Print &p) const
{
	size_t size = 0;
	if (this->count_ == 0)
	{
		size += p.print("There are currently no Unconfirmed Transactions");
	} else {
		for (int i = 0; i < this->count_; i++)
		{
			size += p.print("\ntransaction ");
			size += p.print(i + 1);
			size += p.print(":\n");
			size += this->transactions_[i].printTo(p);
		};
	};
	return size;
};
/*************************************************/

};
};
};
};
