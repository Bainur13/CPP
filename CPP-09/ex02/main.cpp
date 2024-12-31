#include "PmergeMe.hpp"


void printFive(std::string av)
{
	std::istringstream iss(av);
	std::vector<unsigned int>::value_type num;
	int i = 0;
	while (iss >> num)
	{
		if (i < 4)
			std::cout << num << " ";
		i++;
	}
	if (i == 5)
		std::cout << num;
	else if (i > 5)
		std::cout << "[...]";
	std::cout << std::endl;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong number of args" << std::endl;
		return (1);
	}
	std::cout << "Before: ";
	printFive(av[1]);
	
	PmergeMe<std::deque<unsigned int> > test;
	PmergeMe<std::vector<unsigned int> > test2;
	if (test.sort(av[1]) == 1)
		return (1);
	if (test2.sort(av[1]) == 1)
		return (1);
	std::cout << "After: ";
	if (test.getCont().size() > 5)
	{
		for (size_t i = 0; i < 4; i++)
			std::cout << test.getCont()[i] << " ";
		std::cout << "[...]" << std::endl;
	}
	else
	{
		for (size_t i = 0; i < test.getCont().size(); i++)
			std::cout << test.getCont()[i] << " ";
		std::cout << std::endl;
	}
	std::cout << "Time to process a range of " << test.getCont().size() << " elements with a deque: " << test.duration<< "us" << std::endl;
	std::cout << "Time to process a range of " << test2.getCont().size() << " elements with a vector: " << test2.duration << "us" << std::endl;
	return (0);
}
