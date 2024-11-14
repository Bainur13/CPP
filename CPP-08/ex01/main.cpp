#include "Span.hpp"

int main(void)
{
    try
    {
        Span sp;

        sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "error first example :" << e.what() << std::endl;
    }
    try
    {
        Span sp(2);
        sp.addNumbers(1, 10);
        std::cout << "Added 10 numbers" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "error second example :" << e.what() << std::endl;
    }

    std::cout << std::endl
              << "Test personnels" << std::endl;
    Span sp(10000);
    std::vector<int> vec;
    std::srand(time(NULL));
    for (int i = 0; i < 5000; i++)
    {
        int random_int = rand() % 10000;

        vec.push_back(random_int);
        vec.push_back(-random_int);
    }
    try
    {
        sp.addNumbers(vec.begin(), vec.end());
        std::cout << "Shortest = " << sp.shortestSpan() << std::endl;
        std::cout << "Biggest = " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
