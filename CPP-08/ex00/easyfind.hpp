#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception> 
#include <vector>
#include <iostream>

template <typename T>

typename T::iterator easyfind(T &container, int n)
{
   typename T::iterator it = std::find(container.begin(), container.end(), n);
   if (it == container.end())
        throw std::runtime_error("Not found");
    return (it);
}
#endif
