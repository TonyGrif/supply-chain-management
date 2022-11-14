#include <gtest/gtest.h>

#include "../../main/headers/Factory.h"

TEST(FactoryTest, TestConstructor)
{
    Factory fac({1});

    ASSERT_EQ(fac.NumberOfPartTypes(), 1);
    ASSERT_EQ(fac.StorageCapacity(), 20);
    ASSERT_EQ(fac.NumberOfProducts(), 0);
}

TEST(FactoryTest, TestTimeStep)
{
    Factory fac({1, 2});
    Supplier* sPtr = new Supplier({1}, 'A');
    fac.AddSupplier(sPtr);
    Supplier* sPtr2 = new Supplier({2}, 'B');
    fac.AddSupplier(sPtr2);

    Part firstPart;
    fac.AddPart(firstPart);
    Part secondPart(2);
    fac.AddPart(secondPart);

    fac.TimeStep();
    ASSERT_EQ(fac.NumberOfProducts(), 1);
    ASSERT_EQ(fac.NumberOfParts(1), 0);
    ASSERT_EQ(fac.NumberOfParts(2), 0);

    fac.TimeStep();
    fac.TimeStep();
    ASSERT_EQ(fac.NumberOfProducts(), 2);
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

    Part addPart;
    bool added = fac.AddPart(addPart);
    ASSERT_TRUE(added);

    Part secondPart(3);
    added = fac.AddPart(secondPart);
    ASSERT_FALSE(added);
}

TEST(FactoryTest, TestRemovePart)
{
    Factory fac({1});
    
    Part remPart;
    remPart = fac.RemovePart(1);
    ASSERT_EQ(remPart.Type(), -1);

    remPart = fac.RemovePart(3);
    ASSERT_EQ(remPart.Type(), -1);

    Part addPart;
    fac.AddPart(addPart);

    remPart = fac.RemovePart(1);
    ASSERT_EQ(remPart.Type(), 1);
}

TEST(FactoryTest, TestAddSupplier)
{
    Factory fac({1});
    Supplier* supPtr = new Supplier({1});

    ASSERT_EQ(fac.NumberOfSuppliers(), 0);
    fac.AddSupplier(supPtr);
    ASSERT_EQ(fac.NumberOfSuppliers(), 1);
}