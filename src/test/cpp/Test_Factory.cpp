#include <gtest/gtest.h>

#include "../../main/headers/Factory.h"

TEST(FactoryTest, TestConstructor)
{
    Factory fac({1});

    ASSERT_EQ(fac.NumberOfPartTypes(), 1);
}

TEST(FactoryTest, TestTimeStep)
{
    Factory fac({1, 2});

    Part* pPtr;
    pPtr = new Part(1);
    fac.AddPart(pPtr);

    pPtr = new Part(2);
    fac.AddPart(pPtr);

    fac.TimeStep();
    ASSERT_EQ(fac.NumberOfParts(1), 0);
    ASSERT_EQ(fac.NumberOfParts(2), 0);

    pPtr = new Part(1);
    fac.AddPart(pPtr);
    fac.TimeStep();
    ASSERT_EQ(fac.NumberOfParts(1), 1);
    ASSERT_EQ(fac.NumberOfParts(2), 0);
}

TEST(FactoryTest, TestAddNewPartType)
{
    Factory fac({1});
    int num = fac.NumberOfPartTypes();

    fac.AddNewPartType(7);
    ASSERT_EQ(fac.NumberOfPartTypes(), (num+1));

    fac.AddNewPartType(1);
    ASSERT_EQ(fac.NumberOfPartTypes(), (num+1));

    fac.AddNewPartType(0);
    ASSERT_EQ(fac.NumberOfPartTypes(), (num+1));

    fac.AddNewPartType(-1);
    ASSERT_EQ(fac.NumberOfPartTypes(), (num+1));
}

TEST(FactoryTest, TestAddPart)
{
    Factory fac({1});

    Part* pPtr = new Part(1);
    bool added = fac.AddPart(pPtr);
    ASSERT_TRUE(added);

    pPtr = new Part(3);
    added = fac.AddPart(pPtr);
    ASSERT_FALSE(added);
}

TEST(FactoryTest, TestRemovePart)
{
    Factory fac({1});
    Part* ptr;

    ASSERT_FALSE(fac.RemovePart(1));
    ASSERT_FALSE(fac.RemovePart(3));

    ptr = new Part;
    fac.AddPart(ptr);

    ASSERT_TRUE(fac.RemovePart(1));
}