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
         * @brief Conduct one action time step.
         * 
         * During this timestep, the Supplier will increment the counter until a part is ready.
         * If a part is ready, add it to the warehouse.
         */
        void TimeStep();

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
         * @brief Construct a new Supplier object with all the necessary data.
         * 
         * @param types Collection of integers that determines the parts this object produces.
         * @param si Character representation of this supplier.
         * @param pr Integer production rate.
         */
        Supplier(std::initializer_list<int> types, char si = 'A', int pr = 2);

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
        bool AddPart(Part addPart) {
            return this->storage.AddPart(addPart);
        }

        /**
         * @brief Remove a Part from the warehouse.
         * 
         * @param pt Integer representation of the part designation.
         * @return Part pointer to the part being removed, will be NULL if unable to.
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

        /**
         * @brief Return the amount of time steps left until a Part has been produced.
         * 
         * @return Integer (production rate - time elapsed).
         */
        int ReturnTimeTillProduce() const {
            return (this->ProductionRate() - this->timeElapsed);
        }

        /**
         * @brief Return a string representation of this object.
         * 
         * @return String.
         */
        std::string toString() const;

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
         * @brief Integer representation of how many time steps have currently been taken.
         * 
         * This variable will return to zero once it reaches the same number as the partProductionRate.
         */
        int timeElapsed;

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
         * @param pr Integer representation of the production rate.
         */
        void ProductionRate(int pr) {
            this->partProductionRate = pr;
        }
};

#endif
