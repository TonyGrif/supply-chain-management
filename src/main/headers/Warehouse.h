#ifndef WAREHOUSE_H 
#define WAREHOUSE_H

#include "Part.h"

#include <list>
#include <stack>

/**
 * @brief Warehouse class. 
 * 
 * This class is responsible for storing parts of all types.
 */
class Warehouse 
{
    public:
        //using PartsCollection = std::list<std::stack<Part>>;

        /**
         * @brief Construct a new Warehouse object.
         * 
         * Construct a new Warehouse object based on default constructor.
         */
        Warehouse();

    private:
        /**
         * @brief Integer representation of the capacity of this warehouse.
         * 
         * Determines how many of any given part can be stored at once. 
         */
        int sizeOfWarehouse;

        /**
         * @brief Collection of completed parts. 
         */
        //PartsCollection storedParts;
};

#endif