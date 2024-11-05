#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &to_cpy)
{
    *this = to_cpy;
}

Serializer &Serializer::operator=(const Serializer &to_cpy)
{
    if (this == &to_cpy)
        return  *this;
    *this = to_cpy;
    return *this;
}

Serializer::~Serializer(){}


uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

