#include <gtest/gtest.h>

#include "../../main/headers/Supplier.h"

TEST(SupplierTest, TestConstructor)
{
    Supplier sup;

    ASSERT_EQ(sup.Identification(), 'A');
    ASSERT_EQ(sup.ProductionRate(), 2);
}

TEST(SupplierTest, TestIdentification)
{
    Supplier sup;
    Supplier supS('S');

    ASSERT_EQ(sup.ProductionRate(), supS.ProductionRate());

    ASSERT_NE(sup.Identification(), supS.Identification());
    ASSERT_EQ(sup.Identification(), 'A');
    ASSERT_EQ(supS.Identification(), 'S');
}

TEST(SupplierTest, TestProductionRate)
{
    Supplier sup;
    Supplier sup3('A', 3);

    ASSERT_EQ(sup.Identification(), sup3.Identification());

    ASSERT_NE(sup.ProductionRate(), sup3.ProductionRate());
    ASSERT_EQ(sup.ProductionRate(), 2);
    ASSERT_EQ(sup3.ProductionRate(), 3);
}