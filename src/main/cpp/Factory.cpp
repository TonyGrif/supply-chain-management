#include "../headers/Factory.h"

Factory::Factory(std::initializer_list<int> types, int size)
    : storage(types, size)
{
    this->numOfProducts = 0;
}

void Factory::TimeStep() 
{
    for(auto i : this->suppliers) {
        i->TimeStep();
    }

    for(auto i : this->storage)
    {
        // If the parts storage is empty.
        if(i.partStorage.size() == 0)
        {
           for(auto s : this->suppliers)
           {
                if(s->NumberOfParts(i.collectionDesignation) != 0)
                {
                    Part remPart = s->RemovePart(i.collectionDesignation);
                    this->AddPart(remPart);
                }
           }
        }
    }

    for(auto i : this->storage)
    {
        if(i.partStorage.size() == 0) { return; }
    }

    this->numOfProducts++;
    for(auto i : this->storage)
    {
        this->RemovePart(i.collectionDesignation);
    }
}