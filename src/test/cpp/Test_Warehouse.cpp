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
    Part firstPtr;
    Part secondPtr(3);

    bool added = warehouse.AddPart(firstPtr);
    ASSERT_TRUE(added);

    added = warehouse.AddPart(secondPtr);
    ASSERT_FALSE(added);
    ASSERT_EQ(0, warehouse.NumOfParts(3));

    for(int x = 0; x < warehouse.Capacity()-1; x++) {
        Part newPart;
        added = warehouse.AddPart(newPart);
        ASSERT_TRUE(added);
        ASSERT_EQ(warehouse.NumOfParts(1), x+2);
    }

    ASSERT_EQ(warehouse.NumOfParts(1), warehouse.Capacity());

    Part newishPart;
    added = warehouse.AddPart(newishPart);
    ASSERT_FALSE(added);

    ASSERT_EQ(warehouse.Capacity(), warehouse.NumOfParts(1));
    ASSERT_EQ(0, warehouse.NumOfParts(3));
}

TEST(WarehouseTest, TestRemovePart)
{
    Warehouse warehouse({1});

    ASSERT_EQ(warehouse.NumOfParts(1), 0);

    for(int x = 0; x < warehouse.Capacity(); x++) {
        Part pPtr;
        warehouse.AddPart(pPtr);
    }

    ASSERT_EQ(warehouse.NumOfParts(1), warehouse.Capacity());

    for(int x = 0; x < warehouse.Capacity(); x++) {
        Part testPart;
        testPart = warehouse.RemovePart(1);
        
        ASSERT_EQ(testPart.Type(), 1);
        ASSERT_EQ(warehouse.NumOfParts(1), warehouse.Capacity()-(x+1));
    }
    ASSERT_EQ(warehouse.NumOfParts(1), 0);

    Warehouse w3({1, 3}, 5);

    for(int x = 0; x < w3.Capacity(); x++) {
        Part thPtr(x);
        warehouse.AddPart(thPtr);
    }
    Part retPtr = w3.RemovePart(3);
    ASSERT_EQ(retPtr.Type(), 3);
}