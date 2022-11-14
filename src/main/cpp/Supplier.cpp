#include "../headers/Supplier.h"

Supplier::Supplier(char t, int p)
    : storage({0})
{
    this->Identification(t);
    this->ProductionRate(p);
    this->timeElapsed = 0;
}

Supplier::Supplier(std::initializer_list<int> types, char t, int p)
    : storage(types)
{
    this->Identification(t);
    this->ProductionRate(p);
    this->timeElapsed = 0;
}

void Supplier::TimeStep()
{
    this->timeElapsed++;

    if(this->NumberOfPartTypes() == 0) {
        if(this->ReturnTimeTillProduce() == 0) { this->timeElapsed = 0; }
        return;
    }

    if(this->ReturnTimeTillProduce() == 0)
    {
        int lowestType;
        int curLowest = this->storage.Capacity();

        for(auto& i : this->storage)
        {
            if(i.partStorage.size() == 0) { 
                lowestType = i.collectionDesignation;
                curLowest = 0;
                break;
            }
            
            if(i.partStorage.size() < curLowest) {
                lowestType = i.collectionDesignation;
                curLowest = i.partStorage.size();
            }
        }

        if(curLowest == this->storage.Capacity()) {
            this->timeElapsed = 0;
            return;
        }

        Part newPart(lowestType);
        this->AddPart(newPart);

        this->timeElapsed = 0;
    }
}

std::string Supplier::toString() const
{
    std::string string;

    string += "Supplier ";
    string += this->Identification();
    string += " contains ";
    string += this->storage.toString();

    return string;
}