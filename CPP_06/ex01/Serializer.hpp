#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>
#include <iostream>

class Serializer
{
    public:
        Serializer();
        Serializer(const Serializer &src);
        ~Serializer();
        Serializer &operator=(const Serializer &src);

        static uintptr_t serialize(Data* ptr);
        static Data* unserialize(uintptr_t raw);
};

#endif