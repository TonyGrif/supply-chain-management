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

std::string Factory::toString() const
{
    std::string string;

    string += "Production Counter - ";
    string += std::to_string(this->NumberOfProducts());
    string += "\n";

    string += "Current Suppliers";
    string += "\n";
    string += "-----------------";
    string += "\n";

    for(auto i : this->suppliers)
    {
        string += i->toString();
    }

    string += "\n";

    return string;
}