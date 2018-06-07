

#include "gtest/gtest.h"
#include "types/balance.h"

TEST(types, construct_balance_max)
{
  Balance balance("12984403000000000");
	ASSERT_STREQ("129844030.00000000", balance.ark());
	ASSERT_STREQ("12984403000000000", balance.arktoshi());
}

TEST(types, construct_balance_one_ark)
{    
	Balance balance("100000000");
	ASSERT_STREQ("1.00000000", balance.ark());
	ASSERT_STREQ("100000000", balance.arktoshi());
}

TEST(types, construct_balance_one_tenth_ark)
{    
  Balance balance("10000000");
	ASSERT_STREQ(".10000000", balance.ark());
	ASSERT_STREQ("10000000", balance.arktoshi());
}

TEST(types, construct_balance_ten_thousand_arktoshi)
{    
  Balance balance("10000");
	ASSERT_STREQ(".00010000", balance.ark());
	ASSERT_STREQ("10000", balance.arktoshi());
}
