#include "Serializer.hpp"

int main()
{
    Data d = {12, "oue", 3.14f};
    uintptr_t ptr;

    ptr = Serializer::serialize(&d);
    std::cout << "id = " << d.id << ", name = " << d.name << ", value = " << d.value << std::endl;
    std::cout << "ptr = " << ptr << std::endl;
    std::cout << "adress data = " << &d << std::endl;
    Data *new_d = Serializer::deserialize(ptr);
    std::cout << "new data adress = " << new_d << std::endl;
    std::cout << "new ptr = " << Serializer::serialize(new_d) << std::endl;
    std::cout << "id = " << new_d->id << ", name = " << new_d->name << ", value = " << new_d->value << std::endl;

}
