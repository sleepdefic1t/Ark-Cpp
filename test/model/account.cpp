

#include "gtest/gtest.h"
#include "models/account.h"

TEST(model, construct_account)
{
	// Hash msigArray[] = { Hash("") };
	// Hash u_msigArray[] = { Hash("") };
	ARK::Account account(
		"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA",
		"100000000",//Balance("100000000"),
		"100000000", //Balance("100000000"),
		"0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", //Publickey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"),
		0,
		0,
		""//, //Publickey(),
		// msigArray, //Hash[],
		// u_msigArray //Hash[]()
	);

	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", account.address().c_str());
	ASSERT_STREQ("100000000", account.unconfirmed_balance().arktoshi());
	ASSERT_STREQ("100000000", account.balance().arktoshi());
	ASSERT_STREQ("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456", account.public_key().c_str());
	ASSERT_EQ(0, account.unconfirmed_signature());
	ASSERT_EQ(0, account.second_signature());
	ASSERT_STREQ("", account.second_public_key().c_str());
// 	ASSERT_STREQ("", account.multi_signatures());
// 	ASSERT_STREQ("", account.u_multi_signatures());
}

TEST(model, construct_account_make)
{
	const auto passphrase = "bullet parade snow bacon mutual deposit brass floor staff list concert ask";
	auto account = ARK::make_account(ARK::Constants::Networks::Network_ADV::devnet.pubKeyHash, passphrase);
	ASSERT_STREQ("DStZXkgpEjxbG355nQ26vnkp95p24U9tsV", account.address().c_str());
	ASSERT_STREQ("029fdf41a7d69d8efc7b236c21b9509a23d862ea4ed8b13a56e31eee58dbfd97b4", account.public_key().c_str());
}
