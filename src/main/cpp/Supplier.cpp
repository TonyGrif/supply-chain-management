#include "../headers/Supplier.h"

Supplier::Supplier(char t, int p)
    : storage({0})
{
    this->Identification(t);
    this->ProductionRate(p);
}

Supplier::Supplier(std::initializer_list<int> types, char t, int p)
    : storage(types)
{
    this->Identification(t);
    this->ProductionRate(p);
}