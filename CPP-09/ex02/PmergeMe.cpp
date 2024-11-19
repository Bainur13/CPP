#include "PmergeMe.hpp"

template<typename Container>
PmergeMe<Container>::PmergeMe(const Container &cont) : _cont(cont){}

template<typename Container>
PmergeMe<Container>::PmergeMe(const Container &const) : _cont(to_cpy._cont){}

template<typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe<Container> &const)
{
    if (this != &to_cpy)
    {
        _cont = to_cpy._cont;
    }
    return *this;
}

template<typename Container>
void PmergeMe<Container>::addElement(const typename Container::)
{
    
}

