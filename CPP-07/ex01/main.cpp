#include "iter.hpp"
#include <iostream>

void add_one(int &i)
{
    i = i + 1;
}

template <typename T>

void print(T &i)
{
    std::cout << i << " ";
}
int main()
{
    int tab[] = {1,2,3,4,5,6,7,8,9};


    iter(tab, 9, add_one);
    iter(tab, 9, print<int>);
    
}