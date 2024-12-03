#include "PmergeMe.hpp"

int jacobsthal(int n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

bool check_inp(std::string numbs)
{
    int i;

    i = 0;
    while (numbs[i])
    {
        if (!isspace(numbs[i]) && !isdigit(numbs[i]))
            return (0);
        i++;
    }
    return (1);
}



