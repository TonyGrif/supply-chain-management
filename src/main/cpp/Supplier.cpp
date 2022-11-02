#include "../headers/Supplier.h"

Supplier::Supplier(char t, int p)
    : storage()
{
    this->Identification(t);
    this->ProductionRate(p);
    this->timeElapsed = 0;
}

void Supplier::TimeStep()
{
    this->timeElapsed++;

    // NOTE: Does not currently produce other types of parts
    // Will need to be updated when the factory is created
    if(this->ReturnTimeTillProduce() == 0)
    {
        Part* newPart = new Part;
        this->AddPart(newPart);

        delete newPart;
        newPart = NULL;
        this->timeElapsed = 0;
    }
}