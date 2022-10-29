#ifndef FACTORY_H 
#define FACTORY_H

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

    private:
        /**
         * @brief Collection of the available Suppliers.
         * 
         * Collection of Supplier pointers.
         */
        SupplierCollection CollectionOfSuppliers;
};

#endif 