#ifndef SUPPLIER_H 
#define SUPPLIER_H

#include "Warehouse.h"

/**
 * @brief Supplier Class.
 * 
 * This class is responsible for generating parts and sending them to the factory.
 */
class Supplier
{
    public:
        /**
         * @brief Construct a new Supplier object.
         * 
         * Construct a new Supplier object with the default constructor.
         * Default SupplierIdentification will be A.
         * Default PartProductionRate will be 2.
         * Default warehouse constructor called. 
         */
        Supplier(char si = 'A', int pr = 2);

        /**
         * @brief Return the SupplierIdentification.
         * 
         * @return Char held by SupplierIdentification.
         */
        char Identification() const {
            return this->supplierIdentification;
        }

        /**
         * @brief Return the PartProductionRate.
         * 
         * @return Int help by PartProductionRate.
         */
        int ProductionRate() const {
            return this->partProductionRate;
        }

    private:
        /**
         * @brief Character representation of this Supplier.
         * 
         * This variable will determine the Part production type, production rate, and time delay.
         */
        char supplierIdentification;

        /**
         * @brief Integer representation of time steps it takes for this supplier to create a Part.
         */
        int partProductionRate;

        /**
         * @brief Parts storage.
         */
        Warehouse storage;

        /**
         * @brief Set the SupplierIdentification.
         * 
         * @param si Character representation of supplier identification.
         */
        void Identification(char si) {
            this->supplierIdentification = si;
        }

        /**
         * @brief Set the PartProductionRate.
         * 
         * @param pr Integer representation of the production rate
         */
        void ProductionRate(int pr) {
            this->partProductionRate = pr;
        }
};

#endif
