#include "whatever.hpp"

int main()
{
    int a = 5;
    int b = 67;

    std::cout << "Before swapping a = " << a << " and b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swapping a = " << a << " and b = " << b << std::endl;

    std::cout << "The max is " << max(a, b) << std::endl;
    std::cout << "The min is " << min(a, b) << std::endl << std::endl;
    
    a = 2;
    b = 3;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << max(a, b) << std::endl;
    std::string c = "chain";
    std::string d = "chaineplusgrande";
    swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << max(c, d) << std::endl;
    return 0;
}
