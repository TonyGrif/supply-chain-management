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