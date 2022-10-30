#include "../headers/Warehouse.h"

Warehouse::Warehouse(int s, int t)
{
    this->Size(s);
    this->AddPartType(t);
}

void Warehouse::AddPartType(int t)
{
    // Ensure no duplicate part type
    for(auto& i : this->collectionOfParts) {
        if(i.collectionDesignation == t) {
            return;
        }
    }

    PartCollection newPart(t);
    this->collectionOfParts.push_back(newPart);
}

bool Warehouse::AddPart(Part* ptr)
{
    for(auto& i : this->collectionOfParts)
    {
        if(i.collectionDesignation == ptr->Type() && i.partStorage.size() < this->Size()) {
            i.partStorage.push(ptr);
            return true;
        }
    }

    return false;
}