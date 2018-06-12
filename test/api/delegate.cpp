

#include "gtest/gtest.h"
#include "api/api.h"
#include "types/crypto/eckey.h"

namespace
{
	const Publickey darkPubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456");
}

TEST(api, test_delegate_fee)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto delegateFee = _arkManager.delegateFee();
	ASSERT_STREQ("25.00000000", delegateFee.ark());
	ASSERT_STREQ("2500000000", delegateFee.arktoshi());
}

TEST(api, test_delegate_forged_by_account)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto forged_by_account = _arkManager.delegateForgedByAccount(darkPubkey);
	ASSERT_STRNE("0.0", forged_by_account.fees().ark());
	ASSERT_STRNE("0", forged_by_account.fees().arktoshi());
	ASSERT_STRNE("0.0", forged_by_account.forged().ark());
	ASSERT_STRNE("0", forged_by_account.forged().arktoshi());
	ASSERT_STRNE("0.0", forged_by_account.rewards().ark());
	ASSERT_STRNE("0", forged_by_account.rewards().arktoshi());
	
	const auto next_forgers = _arkManager.delegateNextForgers();
	ASSERT_NE(0, next_forgers.current_block());
	ASSERT_NE(0, next_forgers.current_slot());
}

TEST(api, test_delegate_next_forgers)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto next_forgers = _arkManager.delegateNextForgers();
	ASSERT_NE(0, next_forgers.current_block());
	ASSERT_NE(0, next_forgers.current_slot());
}

TEST(api, test_delegate_pub_key)
{
	ARK::API::Manager arkManager(ARK::Constants::Networks::Model::Devnet);
	auto delegate = arkManager.delegate(darkPubkey.c_str());
	ASSERT_STREQ("sleepdeficit", delegate.username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegate.address().c_str());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegate.public_key().c_str());
	ASSERT_STRNE("0", delegate.vote().arktoshi());
	ASSERT_NE(0, delegate.produced_blocks());
	ASSERT_NE(0, delegate.missed_blocks());
	ASSERT_NE(0, delegate.rate());
	ASSERT_NE(0.0, delegate.approval());
	ASSERT_NE(0.0, delegate.productivity());
}

TEST(api, test_delegate_user)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	auto delegate = _arkManager.delegate("sleepdeficit");
	ASSERT_STREQ("sleepdeficit", delegate.username());
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", delegate.address().c_str());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", delegate.public_key().c_str());
	ASSERT_STRNE("0", delegate.vote().arktoshi());
	ASSERT_NE(0, delegate.produced_blocks());
	ASSERT_NE(0, delegate.missed_blocks());
	ASSERT_NE(0, delegate.rate());
	ASSERT_NE(0.0, delegate.approval());
	ASSERT_NE(0.0, delegate.productivity());
}

TEST(api, test_delegate_voters)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	auto voters = _arkManager.delegateVoters(darkPubkey);
	if (voters.count() > 0)
	{
		ASSERT_STREQ("sleepdeficit", voters[1].username());
		ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", voters[1].address().c_str());
		ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", voters[1].public_key().c_str());
	};
}
TEST(api, test_delegate_search)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto search = _arkManager.delegateSearch("sleepdeficit");
	ASSERT_STREQ("sleepdeficit", search.username());

	const auto pubkey = search.public_key();
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", pubkey.c_str());

	const auto& vote = search.vote();
	ASSERT_STRNE("0.0", vote.ark());
	ASSERT_STRNE("0", vote.arktoshi());

	ASSERT_NE(0, search.produced_blocks());
	ASSERT_NE(0, search.missed_blocks());
}

TEST(api, test_delegates_count)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	ASSERT_NE(0, _arkManager.delegatesCount());
}

/*  ==================================  */
/*    BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
//  String delegates = _arkManager.getDelegates();
//    Serial.println("delegates: ");
//    Serial.println(delegates);
//    Serial.println("\n=====\n");
/*  ==================================  */
