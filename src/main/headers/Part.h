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
         */
        Part();

        /**
         * @brief Construct a new Part object using the non-default constructor.
         * 
         * Construct a new Part object with the given parameter. 
         * 
         * @param T Integer representaiton of type.
         */
        Part(int T);

        /**
         * @brief Retun the type to the user.
         * 
         * @return Int type.
         */
        int Type() const;

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
        void Type(int T);
};

#endif
