#include "../headers/Supplier.h"

Supplier::Supplier(char t, int p)
    : storage()
{
    this->Identification(t);
    this->ProductionRate(p);
}