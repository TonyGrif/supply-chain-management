#include "../headers/Supplier.h"

Supplier::Supplier(char t, int p)
    : storage({0})
{
    this->Identification(t);
    this->ProductionRate(p);
}