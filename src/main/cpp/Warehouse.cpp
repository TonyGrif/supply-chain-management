#include "../headers/Warehouse.h"

Warehouse::Warehouse(std::initializer_list<int> types, int s)
{
    this->Size(s);
    
    for(auto& i : types)
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

bool Warehouse::RemovePart(int pt) 
{
    for(auto& i : this->collectionOfParts) {
        if(i.collectionDesignation == pt && i.partStorage.size() != 0) {
            i.partStorage.pop();
            return true;
        }
    }
    return false;
}