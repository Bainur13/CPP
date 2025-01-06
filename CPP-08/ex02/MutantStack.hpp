#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>

template <typename T>

class MutantStack : public std::stack<T, std::deque<T> >
{
    public:
        MutantStack(){}
        ~MutantStack(){}
        MutantStack(const MutantStack &to_cpy)
        {
            this = &to_cpy;
        }
        typedef typename std::deque<T>::iterator iterator;
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};
#endif
