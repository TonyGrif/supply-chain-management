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
         * 
         * @param s Integer for maximum capacity of collection of Parts, default is 5.
         * @param t Integer representation for the type of Part this object stores, default is 1
         */
        Warehouse(int s = 5, int t = 1);

        /**
         * @brief Return the maximum size of this object.
         * 
         * @return Int representation of value stored at sizeOfWarehouse.
         */
        int Size() const {
            return this->sizeOfWarehouse;
        }

        /**
         * @brief Adds a new part type to the collection.
         * 
         * Adds a new part type, checks to ensure that a duplicate part is not being added. 
         * 
         * @param t Integer representation of a Part type. 
         */
        void AddPartType(int t);

        /**
         * @brief Returns the number of Part types this object is currently storing. 
         * 
         * @return Integer representation of number of parts. s
         */
        int NumberOfPartTypes() const {
            int size = 0;
            for(auto& i : this->collectionOfParts) { size++; }
            return size;
        }

    private:
        /**
         * @brief PartCollection struct. 
         * 
         * This struct is resoponsible for determining a type of Part to store and a list of stored parts. 
         */
        struct PartCollection
        {
            /**
             * @brief Construct a new Part Collection object.
             * 
             * @param t Determines the type of Part that will be stored by this object. 
             */
            PartCollection(int t)
                : collectionDesignation(t) 
            {
            }

            /**
             * @brief Determines the type of Part that will be stored. 
             * 
             * The type that will be stored, must be determined when a new struct object is created. 
             */
            const int collectionDesignation;

            /**
             * @brief Collection of Part pointers that are currently stored in this collection.
             */
            std::stack<Part*> partStorage;
        };

        /**
         * @brief Stack collection of the collection of Parts. 
         */
        std::list<PartCollection> collectionOfParts;
        

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
        void Size(int s) {
            this->sizeOfWarehouse = s;
        }
};

#endif