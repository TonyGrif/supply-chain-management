#include "../headers/Factory.h"

Factory::Factory(std::initializer_list<int> types)
    : storage(types)
{
}

void Factory::TimeStep() 
{
    for(auto& i : this->storage) 
    {
        if(i.partStorage.size() == 0) { return; }
    }

    for(auto& i : this->storage)
    {
        i.partStorage.pop();
    }
}