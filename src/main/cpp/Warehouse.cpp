#include "../headers/Warehouse.h"

Warehouse::Warehouse(std::initializer_list<int> types, int s)
{
    this->Capacity(s);
    
    for(auto i : types)
    {
        this->AddPartType(i);
    }
}

void Warehouse::AddPartType(int t)
{
    // Zeros and Negatives not allowed
    if(t <= 0) { return; }

    // Ensure no duplicate part type
    for(auto& i : this->collectionOfParts) {
        if(i.collectionDesignation == t) {
            return;
        }
    }

    PartCollection newPart(t);
    this->collectionOfParts.push_back(newPart);
}

bool Warehouse::AddPart(Part addPart)
{
    for(auto& i : this->collectionOfParts)
    {
        if(i.collectionDesignation == addPart.Type() && i.partStorage.size() < this->Capacity()) {
            i.partStorage.push(addPart);
            return true;
        }
    }

    return false;
}

Part Warehouse::RemovePart(int pt) 
{
    for(int x = 0; x < this->collectionOfParts.size(); x++)
    {
        if(this->collectionOfParts[x].collectionDesignation == pt && this->collectionOfParts[x].partStorage.size() != 0)
        {
            Part retPart(pt);
            this->collectionOfParts[x].partStorage.pop();
            return retPart;
        }
    }
    return -1;
}