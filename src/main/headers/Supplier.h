#ifndef SUPPLIER_H 
#define SUPPLIER_H

#include "Part.h"

/**
 * @brief Supplier Class.
 * 
 * This class is responsible for generating parts and sending them to the factory.
 * @TODO: Create warehouse to store parts.
 */
class Supplier
{
    public:
        /**
         * @brief Construct a new Supplier object.
         * 
         * Construct a new Supplier object with the default constructor.
         * Default SupplierIdentification will be A.
         * Default PartProducrtionRate will be 2.
         */
        Supplier(char si = 'A', int pr = 2);

        /**
         * @brief Return the SupplierIdentification.
         * 
         * @return Char held by SupplierIdentification.
         */
        char Identification() const;

        /**
         * @brief Return the PartProductionRate.
         * 
         * @return Int help by PartProductionRate.
         */
        int ProductionRate() const;

    private:
        /**
         * @brief Character representation of this Supplier.
         * 
         * This variable will determine the Part production type, production rate, and time delay.
         */
        char SupplierIdentification;

        /**
         * @brief Integer representation of time steps it takes for this supplier to create a Part.
         */
        int PartProductionRate;

        /**
         * @brief Set the SupplierIdentification.
         * 
         * @param si Character representation of supplier identification.
         */
        void Identification(char si);

        /**
         * @brief Set the PartProductionRate.
         * 
         * @param pr Integer representation of the production rate
         */
        void ProductionRate(int pr);
};

#endif
