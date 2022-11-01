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
         * Construct a new Factory object based on the default constructor. 
         * Default Warehouse will be set to defaults.
         */
        Factory();

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
        bool AddPart(Part* pPtr) {
            return this->storage.AddPart(pPtr);
        }

        /**
         * @brief Remove a Part from the warehouse.
         * 
         * @param pt Integer representation of the part designation
         * @return True if part was removed.
         * @return False if part was not removed.
         */
        bool RemovePart(int pt) {
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

    private:
        /**
         * @brief Warehouse collection for all the parts a Factory will need.
         */
        Warehouse storage;
};

#endif 