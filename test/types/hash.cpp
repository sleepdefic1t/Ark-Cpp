

#include "gtest/gtest.h"
#include "types/hash.h"

TEST(types, construct_hash)
{
	Hash hash("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23");
	ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", hash.c_str());
}

TEST(types, construct_hash_empty)
{
	Hash hash("");
	ASSERT_STREQ("", hash.c_str());
}
