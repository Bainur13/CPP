#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <stdint.h>

struct Data
{
    int id;
    std::string name;
    float value;
};

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data *deserialize(uintptr_t raw);

    private:
        Serializer();
        Serializer(const Serializer &to_cpy);
        Serializer &operator=(const Serializer &to_cpy);

        ~Serializer();
};

#endif
