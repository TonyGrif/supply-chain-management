#include <gtest/gtest.h>

#include "../../main/headers/Part.h"

using ::testing::Ne;

TEST(PartTest, TestConstructor)
{
    Part part;
    Part typePart(4);

    ASSERT_EQ(part.Type(), 1);
    ASSERT_NE(part.Type(), typePart.Type());
    ASSERT_EQ(typePart.Type(), 4);
}

TEST(PartTest, TestSetType)
{
    Part part;
    Part typePart(4);

    ASSERT_EQ(part.Type(), 1);
    ASSERT_NE(part.Type(), typePart.Type());
    ASSERT_EQ(typePart.Type(), 4);
}