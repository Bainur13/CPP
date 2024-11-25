#include "PmergeMe.hpp"

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

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong number of args" << std::endl;
		return (1);
	}
	PmergeMe<> test;
    PmergeMe<std::deque<unsigned int> > test2;
	if (!check_inp(av[1]))
	{
		std::cerr << "Invalid arg" << std::endl;
		return (1);
	}
	test.addElements(av[1]);
    test.sort();
    test.prints();
}
