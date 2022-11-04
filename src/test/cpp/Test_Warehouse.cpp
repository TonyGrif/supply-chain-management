#include <gtest/gtest.h>

#include "../../main/headers/Warehouse.h"

using ::testing::Ne;

TEST(WarehouseTest, TestConstructor)
{
    Warehouse warehouse({1});
    Warehouse warehouse3({1}, 3);

    ASSERT_EQ(warehouse.Capacity(), 5);
    ASSERT_NE(warehouse.Capacity(), warehouse3.Capacity());
    ASSERT_EQ(warehouse3.Capacity(), 3);

    ASSERT_EQ(warehouse.NumberOfPartTypes(), 1);
    ASSERT_EQ(warehouse3.NumberOfPartTypes(), 1);

    ASSERT_EQ(warehouse.NumOfParts(1), 0);
    ASSERT_EQ(warehouse3.NumOfParts(3), 0);
}

TEST(WarehouseTest, TestVariableConstructor)
{
    Warehouse warehouse({1});
    Warehouse bigWarehouse({1, 2, 3, 4, 5, 6, 7});

    ASSERT_NE(warehouse.NumberOfPartTypes(), bigWarehouse.NumberOfPartTypes());
    ASSERT_EQ(bigWarehouse.NumberOfPartTypes(), 7);

    ASSERT_EQ(warehouse.Capacity(), bigWarehouse.Capacity());
}

TEST(WarehouseTest, TestWarehouseSize)
{
    Warehouse warehouse({1});
    Warehouse warehouse3({1}, 3);

    ASSERT_EQ(warehouse.Capacity(), 5);
    ASSERT_NE(warehouse.Capacity(), warehouse3.Capacity());
    ASSERT_EQ(warehouse3.Capacity(), 3);
}

TEST(WarehouseTest, TestAddPartType)
{
    Warehouse warehouse({1});

    int currentNumber = warehouse.NumberOfPartTypes();
    warehouse.AddPartType(5);

    ASSERT_EQ(warehouse.NumberOfPartTypes(), (currentNumber+1));

    currentNumber = warehouse.NumberOfPartTypes();
    warehouse.AddPartType(5);

    // Should not change
    ASSERT_EQ(warehouse.NumberOfPartTypes(), currentNumber);

    ASSERT_EQ(0, warehouse.NumOfParts(5));

    currentNumber = warehouse.NumberOfPartTypes();
    warehouse.AddPartType(0);
    ASSERT_EQ(warehouse.NumberOfPartTypes(), currentNumber);

    warehouse.AddPartType(-1);
    ASSERT_EQ(warehouse.NumberOfPartTypes(), currentNumber);
}

TEST(WarehouseTest, TestAddPart)
{
    Warehouse warehouse({1});
    Part *firstPtr = new Part;
    Part *secondPtr = new Part(3);

    bool added = warehouse.AddPart(firstPtr);
    ASSERT_TRUE(added);

    added = warehouse.AddPart(secondPtr);
    ASSERT_FALSE(added);
    ASSERT_EQ(0, warehouse.NumOfParts(3));

    for(int x = 0; x < warehouse.Capacity()-1; x++) {
        firstPtr = new Part;
        added = warehouse.AddPart(firstPtr);
        ASSERT_TRUE(added);
    }

    firstPtr = new Part;
    added = warehouse.AddPart(firstPtr);
    ASSERT_FALSE(added);

    ASSERT_EQ(warehouse.Capacity(), warehouse.NumOfParts(1));
    ASSERT_EQ(0, warehouse.NumOfParts(3));
}

TEST(WarehouseTest, TestRemovePart)
{
    Warehouse warehouse({1});
    Part* pPtr;

    ASSERT_FALSE(warehouse.RemovePart(1));

    for(int x = 0; x < warehouse.Capacity(); x++) {
        pPtr = new Part;
        warehouse.AddPart(pPtr);
    }

    ASSERT_FALSE(warehouse.RemovePart(3));

    for(int x = 0; x < warehouse.Capacity(); x++) {
        ASSERT_TRUE(warehouse.RemovePart(1));
    }
}