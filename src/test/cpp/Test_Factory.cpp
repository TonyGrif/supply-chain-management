#include <gtest/gtest.h>

#include "../../main/headers/Factory.h"

TEST(FactoryTest, TestConstructor)
{
    Factory fac;

    ASSERT_EQ(fac.NumberOfPartTypes(), 1);
}

TEST(FactoryTest, TestAddNewPartType)
{
    Factory fac;
    int num = fac.NumberOfPartTypes();

    fac.AddNewPartType(7);
    ASSERT_EQ(fac.NumberOfPartTypes(), (num+1));

    fac.AddNewPartType(1);
    ASSERT_EQ(fac.NumberOfPartTypes(), (num+1));
}