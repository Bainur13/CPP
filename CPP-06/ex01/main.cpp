#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Expected one argument" << std::endl;
    }
    ScalarConverter::convert(av[1]);
}