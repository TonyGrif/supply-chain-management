#include <gtest/gtest.h>

#include "../../main/headers/Warehouse.h"

using ::testing::Ne;

TEST(WarehouseTest, TestConstructor)
{
    Warehouse warehouse;
    Warehouse warehouse3(3);

    ASSERT_EQ(warehouse.Size(), 5);
    ASSERT_NE(warehouse.Size(), warehouse3.Size());
    ASSERT_EQ(warehouse3.Size(), 3);

    ASSERT_EQ(warehouse.NumberOfPartTypes(), 1);
    ASSERT_EQ(warehouse3.NumberOfPartTypes(), 1);
}

TEST(WarehouseTest, TestWarehouseSize)
{
    Warehouse warehouse;
    Warehouse warehouse3(3);

    ASSERT_EQ(warehouse.Size(), 5);
    ASSERT_NE(warehouse.Size(), warehouse3.Size());
    ASSERT_EQ(warehouse3.Size(), 3);
}

TEST(WarehouseTest, TestAddPartType)
{
    Warehouse warehouse;

    int currentNumber = warehouse.NumberOfPartTypes();
    warehouse.AddPartType(5);

    ASSERT_EQ(warehouse.NumberOfPartTypes(), (currentNumber+1));
}