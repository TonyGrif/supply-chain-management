#include <gtest/gtest.h>

#include "../../main/headers/Supplier.h"

TEST(SupplierTest, TestConstructor)
{
    Supplier sup;

    ASSERT_EQ(sup.Identification(), 'A');
    ASSERT_EQ(sup.ProductionRate(), 2);

    ASSERT_EQ(sup.NumberOfPartTypes(), 1);
    ASSERT_EQ(sup.NumberOfParts(1), 0);
}

TEST(SupplierTest, TestAddNewPart)
{
    Supplier sup;
    int num = sup.NumberOfPartTypes();

    sup.AddNewPartType(7);
    ASSERT_EQ(sup.NumberOfPartTypes(), (num+1));

    sup.AddNewPartType(1);
    ASSERT_EQ(sup.NumberOfPartTypes(), (num+1));
}

TEST(SupplierTest, TestAddPart)
{
    Supplier sup;
    Part* pPtr = new Part(1);
    ASSERT_TRUE(sup.AddPart(pPtr));

    pPtr = new Part(3);
    ASSERT_FALSE(sup.AddPart(pPtr));
}

TEST(SupplierTest, TestRemovePart)
{
    Supplier sup;
    Part* ptr;

    ASSERT_FALSE(sup.RemovePart(1));
    ASSERT_FALSE(sup.RemovePart(3));

    ptr = new Part;
    sup.AddPart(ptr);

    ASSERT_TRUE(sup.RemovePart(1));
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