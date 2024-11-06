#include "Array.hpp"
#include <string>

int main()
{
    std::cout << "Creating an empty array" << std::endl;
    Array<int> tab(10);

    std::cout << "Array of 10 created" << std::endl;
    std::cout << "Check right size = " << tab.size() << std::endl;

    try
    {
        for (int i = 0; i < 11; i++)
            tab[i] = i + 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < 10; i++)
        std::cout << tab[i] << std::endl;

    Array<int> tab2(tab);

    std::cout << std::endl
              << "Copy of main tab" << std::endl;

    for (int i = 0; i < 10; i++)
        std::cout << tab[i] << std::endl;

     std::cout << std::endl
              << "Array of string" << std::endl;
    Array<std::string> s_tab(3);
    std::cout << "size of s_tab = " << s_tab.size() << std::endl;
    s_tab[0] = "lalila";
    s_tab[1] = "Paris";
    s_tab[2] = "Marseille";
    for (int i = 0; i < 3; i++)
        std::cout << s_tab[i] << std::endl;
}