#include "../headers/Factory.h"

Factory::Factory(std::initializer_list<int> types)
    : storage(types)
{
}