#ifndef WAREHOUSE_H 
#define WAREHOUSE_H

#include "Part.h"

#include <list>
#include <stack>
#include <initializer_list>

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
         * @param types Collection of integers to determine part types stored in this object.
         * @param s Integer for maximum capacity of collection of Parts, default is 5.
         */
        Warehouse(std::initializer_list<int> types, int s = 5);
    
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
         * If a zero or negative number is passed in, do not add and return.
         * 
         * @param t Integer representation of a Part type. 
         */
        void AddPartType(int t);

        /**
         * @brief Returns the number of Part types this object is currently storing. 
         * 
         * @return Integer representation of number of parts.
         */
        int NumberOfPartTypes() const {
            int size = 0;
            for(auto& i : this->collectionOfParts) { size++; }
            return size;
        }

        /**
         * @brief Add a Part pointer to the Part collection.
         * 
         * @param pPtr Pointer to a Part object to be added if possible.
         * 
         * @return True if the Part was sucessfully added
         * @return false if Part was not added as the warehouse does not store the type of Part given.
         */
        bool AddPart(Part* pPtr);

        /**
         * @brief Remove a Part of a given type.
         * 
         * @param pt
         * 
         * @return True if there is a Part of type to remove.
         * @return False if there is no Part to remove of type. 
         */
        bool RemovePart(int pt);

        /**
         * @brief Return the number of Parts of a given type currently stored. 
         * 
         * @param pt Integer representation of Part type.
         * @return Integer number of Parts currently stored. 
         */
        int NumOfParts(int pt) const {
            for(auto& i : this->collectionOfParts) {
                if(i.collectionDesignation == pt) { return i.partStorage.size(); }
            }
            return 0;
        }

    private:
        /**
         * @brief PartCollection struct. 
         * 
         * This struct is responsible for determining a type of Part to store and a list of stored parts. 
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