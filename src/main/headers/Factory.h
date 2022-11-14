#ifndef FACTORY_H 
#define FACTORY_H

#include "Warehouse.h"
#include "Supplier.h"

#include <list>

/**
 * @brief Factory class. 
 * 
 * This class is responsible for querying Suppliers for Parts and creating products. 
 */
class Factory
{
    public:
        using SupplierCollection = std::list<Supplier*>;

        /**
         * @brief Construct a new Factory object.
         * 
         * @param types Intitializer list of integers to determine the Part types this factory will require
         */
        Factory(std::initializer_list<int> types, int size = 20);

        /**
         * @brief Carry out one time step for this factory.
         * 
         * If all parts of storage are filled, decrement each and create one product.
         * If one or more parts of storage are empty, place orders for those parts from one of the suppliers.
         */
        void TimeStep();

        /**
         * @brief Add a new part type to the storage variable.
         * 
         * @param t Integer representation of the part type.
         */
        void AddNewPartType(int t) {
            this->storage.AddPartType(t);
        }

        /**
         * @brief Return the number of part types that storage is currently holding.
         * 
         * @return Int number of part types in play for this object.
         */
        int NumberOfPartTypes() const {
            return this->storage.NumberOfPartTypes();
        }

        /**
         * @brief Add Part to the warehouse for storage.
         * 
         * @param pPtr Part pointer to a new Part to be added. 
         * @return True if the Part was successfully added.
         * @return False if the Part was not added to the collection.
         */
        bool AddPart(Part toAdd) {
            return this->storage.AddPart(toAdd);
        }

        /**
         * @brief Remove a Part from the warehouse.
         * 
         * @param pt Integer representation of the part designation
         * @return Part object.
         */
        Part RemovePart(int pt) {
            return this->storage.RemovePart(pt);
        }

        /**
         * @brief Return the number of Parts of a given type.
         * 
         * @param pt Integer representation of a Part type.
         * @return Integer number of Parts.
         */
        int NumberOfParts(int pt) const {
            return this->storage.NumOfParts(pt);
        }

        /**
         * @brief Add a supplier to the factory's collection.
         * 
         * @param supPtr Pointer to a supplier.
         */
        void AddSupplier(Supplier* supPtr) {
            this->suppliers.push_back(supPtr);
        }

        /**
         * @brief Return the number of Suppliers currently collected in this factory.
         * 
         * @return Integer number of suppliers collected.
         */
        int NumberOfSuppliers() const {
            return this->suppliers.size();
        }

        /**
         * @brief Return the maximum number of parts (of one type) that can be stored in this factory.
         * 
         * @return Integer capacity of the warehouse.
         */
        int StorageCapacity() const {
            return this->storage.Capacity();
        }

        /**
         * @brief Return the number of products that have been created by this object.
         * 
         * @return Integer.
         */
        int NumberOfProducts() const {
            return this->numOfProducts;
        }

    private:
        /**
         * @brief Warehouse collection for all the parts a Factory will need.
         */
        Warehouse storage;

        /**
         * @brief Collection of potential suppliers for this factory.
         */
        SupplierCollection suppliers;        

        /**
         * @brief Stores the number of products that have been created by this object.
         */
        int numOfProducts;
};

#endif 