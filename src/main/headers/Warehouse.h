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
        /**
         * @brief Construct a new Warehouse object.
         * 
         * Construct a new Warehouse object based on default constructor.
         */
        Warehouse();

        /**
         * @brief Return the maximum size of this object.
         * 
         * @return Int representation of value stored at sizeOfWarehouse.
         */
        int Size() const;

    private:
        /**
         * @brief PartCollection struct. 
         * 
         * This struct is resoponsible for determining a type of Part to store and a list of stored parts. 
         */
        struct PartCollection
        {
            /**
             * @brief Determines the type of Part that will be stored. 
             */
            int collectionDesignation;

            /**
             * @brief Collection of Part pointers that are currently stored in this collection.
             */
            std::list<Part*> partStorage;
        };

        /**
         * @brief Stack collection of the collection of Parts. 
         */
        std::stack<PartCollection> collectionOfParts;
        

        /**
         * @brief Integer representation of the capacity of this warehouse.
         * 
         * Determines how many of any given part can be stored at once. 
         */
        int sizeOfWarehouse;

        /**
         * @brief Set the maximum size of this object.
         * 
         * @param s Integer representation of maximum size. 
         */
        void Size(int s);
};

#endif