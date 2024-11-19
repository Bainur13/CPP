#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cout << "Wrong numbers of arg" << std::endl, 1);
    try
    {
        RPN calculus;
        calculus.handleString(av[1]);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
