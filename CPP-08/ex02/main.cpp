#include "MutantStack.hpp"
#include <list>

int main()
{
    try
    {
        std::cout << "Monster Stack :" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << std::endl
                  << "List Stack :" << std::endl;

        std::list<int> l;
        l.push_back(5);
        l.push_back(17);
        std::cout << l.back() << std::endl;
        l.pop_back();
        std::cout << l.size() << std::endl;
        l.push_back(3);
        l.push_back(5);
        l.push_back(737);
        l.push_back(0);
        std::list<int>::iterator it = l.begin();
        std::list<int>::iterator ite = l.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << std::endl
                  << "Mutant stack :" << std::endl;
        MutantStack<int> mstackv2;
        mstackv2.push(88);
        mstackv2.push(77);
        mstackv2.push(12);
        mstackv2.push(18);
        mstackv2.push(345);
        mstackv2.push(123);
        MutantStack<int>::iterator it = mstackv2.end();
        while (it != mstackv2.begin())
        {
            it--;
            std::cout << *it << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << std::endl
                  << "Iterator basic:" << std::endl;
        std::list<int> listv2;
        listv2.push_back(88);
        listv2.push_back(77);
        listv2.push_back(12);
        listv2.push_back(18);
        listv2.push_back(345);
        listv2.push_back(123);
        std::list<int>::iterator it = listv2.end();
        while (it != listv2.begin())
        {
            it--;
            std::cout << *it << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
