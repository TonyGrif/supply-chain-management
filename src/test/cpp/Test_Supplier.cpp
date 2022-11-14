#include <gtest/gtest.h>

#include "../../main/headers/Supplier.h"

TEST(SupplierTest, TestConstructor)
{
    Supplier sup;

    ASSERT_EQ(sup.Identification(), 'A');
    ASSERT_EQ(sup.ProductionRate(), 2);

    ASSERT_EQ(sup.NumberOfPartTypes(), 0);
    ASSERT_EQ(sup.NumberOfParts(0), 0);
    ASSERT_EQ(sup.ReturnTimeTillProduce(), sup.ProductionRate());
}

TEST(SupplierTest, TestTimeStep)
{
    Supplier sup({1});
    Supplier zeroSup({0});

    for(int x = 0; x < sup.ProductionRate(); x++) {
        ASSERT_EQ(sup.ReturnTimeTillProduce(), sup.ProductionRate()-x);
        sup.TimeStep();
        zeroSup.TimeStep();
    }

    ASSERT_EQ(sup.NumberOfParts(1), 1);
    ASSERT_EQ(sup.ReturnTimeTillProduce(), sup.ProductionRate());

    ASSERT_EQ(zeroSup.NumberOfParts(0), 0);
    ASSERT_EQ(zeroSup.ReturnTimeTillProduce(), zeroSup.ProductionRate());

    Supplier multSup({1, 3});
    for(int x = 0; x < multSup.ProductionRate(); x++) {
        multSup.TimeStep();
    }

    ASSERT_EQ(multSup.NumberOfParts(1), 1);
    ASSERT_EQ(multSup.NumberOfParts(3), 0);

    for(int x = 0; x < multSup.ProductionRate(); x++) {
        multSup.TimeStep();
    }

    ASSERT_EQ(multSup.NumberOfParts(1), 1);
    ASSERT_EQ(multSup.NumberOfParts(3), 1);
}

TEST(SupplierTest, TestVariableConstructor)
{
    Supplier bigSup({1, 2, 3, 4, 5}, 'B', 3);

    ASSERT_EQ(bigSup.Identification(), 'B');
    ASSERT_EQ(bigSup.ProductionRate(), 3);

    ASSERT_EQ(bigSup.NumberOfPartTypes(), 5);
    ASSERT_EQ(bigSup.ReturnTimeTillProduce(), bigSup.ProductionRate());
}

TEST(SupplierTest, TestAddNewPartType)
{
    Supplier sup;
    int num = sup.NumberOfPartTypes();
    ASSERT_EQ(num, 0);

    sup.AddNewPartType(7);
    ASSERT_EQ(sup.NumberOfPartTypes(), (num+1));
    num = sup.NumberOfPartTypes();

    sup.AddNewPartType(1);
    ASSERT_EQ(sup.NumberOfPartTypes(), (num+1));

    ASSERT_EQ(sup.ReturnTimeTillProduce(), sup.ProductionRate());
}

TEST(SupplierTest, TestAddPart)
{
    Supplier sup({1});
    Part firstPart;
    ASSERT_TRUE(sup.AddPart(firstPart));

    Part secondPart(3);
    ASSERT_FALSE(sup.AddPart(secondPart));

    ASSERT_EQ(sup.ReturnTimeTillProduce(), sup.ProductionRate());
}

TEST(SupplierTest, TestRemovePart)
{
    Supplier sup({1});

    Part firstPart;
    sup.AddPart(firstPart);

    Part getPart = sup.RemovePart(1);
    ASSERT_EQ(getPart.Type(), 1);

    Supplier sup2({1, 2});

    Part secPart(2);
    sup2.AddPart(secPart);
    getPart = sup2.RemovePart(2);

    ASSERT_EQ(getPart.Type(), 2);

    ASSERT_EQ(sup.ReturnTimeTillProduce(), sup.ProductionRate());
}

TEST(SupplierTest, TestIdentification)
{
    Supplier sup;
    Supplier supS('S');

    ASSERT_EQ(sup.ProductionRate(), supS.ProductionRate());

    ASSERT_NE(sup.Identification(), supS.Identification());
    ASSERT_EQ(sup.Identification(), 'A');
    ASSERT_EQ(supS.Identification(), 'S');

    ASSERT_EQ(sup.ReturnTimeTillProduce(), sup.ProductionRate());
    ASSERT_EQ(supS.ReturnTimeTillProduce(), supS.ProductionRate());
}

TEST(SupplierTest, TestProductionRate)
{
    Supplier sup;
    Supplier sup3('A', 3);

    ASSERT_EQ(sup.Identification(), sup3.Identification());

    ASSERT_NE(sup.ProductionRate(), sup3.ProductionRate());
    ASSERT_EQ(sup.ProductionRate(), 2);
    ASSERT_EQ(sup3.ProductionRate(), 3);

    ASSERT_EQ(sup.ReturnTimeTillProduce(), sup.ProductionRate());
    ASSERT_EQ(sup3.ReturnTimeTillProduce(), sup3.ProductionRate());
}

TEST(SupplierTest, TestTimeTillProduced)
{
    Supplier sup;

    ASSERT_EQ(sup.ReturnTimeTillProduce(), sup.ProductionRate());

    for(int x = 0; x < sup.ProductionRate(); x++)
    {
        ASSERT_EQ(sup.ReturnTimeTillProduce(), sup.ProductionRate()-x);
        sup.TimeStep();
    }

    ASSERT_EQ(sup.ReturnTimeTillProduce(), sup.ProductionRate());
}