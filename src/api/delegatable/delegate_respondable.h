

#ifndef DELEGATE_RESPONDABLE_H
#define DELEGATE_RESPONDABLE_H

#include "utilities/platform.h"
#include "utilities/json.h"

#include "models/delegate.h"
#include "models/voter.h"
#include "types/address.h"
#include "types/balance.h"
#include "types/crypto/eckey.h"

#include <array>
#include <cstdio>
#include <cstring>
#include <memory>

namespace ARK
{
namespace API
{
namespace Delegate
{
namespace Respondable
{

/*************************************************
* Constructor
**************************************************/
struct Delegates :
		public Printable
{
	private:
		size_t totalCount_;
    	std::unique_ptr<ARK::Delegate[]> delegates_;

	public:
		Delegates(size_t newCount);

		size_t totalCount() const;
		void setTotalCount(int newCount);

		const ARK::Delegate &operator[](size_t index) const;
		ARK::Delegate &operator[](size_t index);

		virtual size_t printTo(Print &p) const;
};
/*************************************************/

/*************************************************
* ARK::API::Delegate::Respondable::ForgedByAccount
*
* @param: const Balance
* @param: const Balance
* @param: const Balance
*
* @brief: Model for Delegate Forging Totals API Response
**************************************************/
struct ForgedByAccount :
		public Printable
{
	protected:
		Balance fees_;
		Balance rewards_;
		Balance forged_;

	public:
		ForgedByAccount(
				const char *const newFees,
				const char *const newRewards,
				const char *const newForged
		);

		const Balance& fees() const noexcept { return fees_; }
		const Balance& rewards() const noexcept { return rewards_; }
		const Balance& forged() const noexcept { return forged_; }

		virtual size_t printTo(Print &p) const;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Delegate::Respondable::NextForgers
*
* @param: char[64]
* @param: char[64]
* @param: Publickey* const
*
* @brief: Model for Next 10 Forging Delegate Publickeys API Response
**************************************************/
struct NextForgers :
		public Printable
{
	protected:
		int currentBlock_;
		int currentSlot_;
		Publickey delegate_keys_[10];

	public:
		NextForgers(
				int newCB,
				int newCS,
				const Publickey *const newDelegateKeys
		);

		int current_block() const noexcept { return currentBlock_; }
		int current_slot() const noexcept { return currentSlot_; }
		const Publickey *delegate_keys() const noexcept { return delegate_keys_; }

		virtual size_t printTo(Print &p) const;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Delegate::Respondable::Search
*
* @brief:	Model for Delegate Search API Response
**************************************************/
struct Search :
		public Printable
{
	protected:
		char username_[20 + 1];
		Address address_;
		Publickey publicKey_;
		Balance vote_;
		int producedblocks_;
		int missedblocks_;

	public:
		Search(
				const char *const newUsername,
				const char *const newAddress,
				const char *const newPublickey,
				const char *const newVote,
				int newProducedBlocks,
				int newMissedBlocks
		);

		const char* username() const noexcept { return username_; }
		const Address& address() const noexcept { return address_; }
		const Publickey& public_key() const noexcept { return publicKey_; }
		const Balance& vote() const noexcept { return vote_; }
		int produced_blocks() const noexcept { return producedblocks_; }
		int missed_blocks() const noexcept { return missedblocks_; }

		virtual size_t printTo(Print &p) const;	
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
* ARK::API::Delegate::Respondable::Voters
*
* @param: size_t
* @param: ARK::Voter* const
*
* @brief: Model for Delegate Voters API Response
**************************************************/
struct Voters :
		public Printable
{
	private:
		size_t count_;
    	std::unique_ptr<ARK::Voter[]> voters_;

	public:
		Voters(size_t c) : count_(c), voters_(new ARK::Voter[c]) {}

		size_t count() const;

		const Voter &operator[](size_t index) const;
		Voter &operator[](size_t index);

		virtual size_t printTo(Print &p) const;
};
/*************************************************/

};
};
};
};

#endif
