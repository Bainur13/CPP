#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;

    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(10);
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << *it << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << &e << std::endl;
    }
    try {
        std::vector<int>::iterator it = easyfind(vec, 50);
        std::cout << *it << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}