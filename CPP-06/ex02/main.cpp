#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <iostream>
#include <typeinfo>

Base *generate(void)
{
    long rand;

    rand = (random() * (4 - 1) / RAND_MAX) + 1;
    if (rand == 1)
    {
        std::cout << "A has been created" << std::endl;
        return new A;
    }
    else if (rand == 2)
    {
        std::cout << "B has been created" << std::endl;
        return new B;
    }
    else
    {
        std::cout << "C has been created" << std::endl;
        return new C;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p) != NULL)
    {
        std::cout << "The class of the object pointer is A" << std::endl;
        return;
    }
    if (dynamic_cast<B*>(p) != NULL)
    {
        std::cout << "The class of the object pointer is B" << std::endl;
        return;
    }
    if (dynamic_cast<C*>(p) != NULL)
    {
        std::cout << "The class of the object pointer is C" << std::endl;
        return;
    }
}

void identify(Base &p)
{
    try {
        A a = dynamic_cast<A&>(p);
        std::cout << "The class of the object reference is A. Adress :" << &a << std::endl;
        return ;
    }
    catch(std::bad_cast &e){
    }
    try {
        B b = dynamic_cast<B&>(p);
        std::cout << "The class of the object reference is B. Adress : " << &b << std::endl;
        return ;
    }
    catch(std::bad_cast &e){
    }
    try {
        C c = dynamic_cast<C&>(p);
        std::cout << "The class of the object reference is C. Adress : " << &c << std::endl;
        return ;
    }
    catch(std::bad_cast &e){
        std::cout << "The object is not an instance of A, B or C" << std::endl;
    }
}

int main()
{
    Base *tower;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Object number : " << i << std::endl;
        tower = generate();
        std::cout << "Identifying pointer :" << std::endl;
        identify(tower);
        std::cout << "Identifying reference :" << std::endl;
        identify(*tower);
        delete(tower);
        if (i != 9)
            std::cout << std::endl << std::endl;
    }
    return (0);
}
