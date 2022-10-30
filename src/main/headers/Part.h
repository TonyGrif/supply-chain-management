#ifndef PART_H 
#define PART_H

/**
 * @brief Part class.
 * 
 * This class is responsible for containing a part type to be used to create a product. 
 */
class Part
{
    public:
        /**
         * @brief Construct a new Part object.
         * 
         * Construct a new Part object and set the default type to 1.
         * 
         * @param T Integer representaiton of type.
         */
        Part(int T = 1);

        /**
         * @brief Retun the type to the user.
         * 
         * @return Int type.
         */
        int Type() const {
            return this->type;
        }

    private:
        /**
         * @brief Integer representation of the type of object this is.
         */
        int type;

        /**
         * @brief Set the value of Type.
         * 
         * @param T Integer representation of type.
         */
        void Type(int T) {
            this->type = T;
        }
};

#endif
