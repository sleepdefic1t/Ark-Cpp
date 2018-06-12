

#include "gtest/gtest.h"
#include "types/address.h"

TEST(types, construct_address)
{
	Address address("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA");
	ASSERT_STREQ("DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA", address.c_str());
}
