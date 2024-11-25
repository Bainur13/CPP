#include "PmergeMe.hpp"

template <typename Container> PmergeMe<Container>::PmergeMe()
{
}

template <typename Container> PmergeMe<Container>::PmergeMe(const PmergeMe &to_cpy) : _cont(to_cpy._cont)
{
}

template <typename Container> PmergeMe<Container>::PmergeMe(const Container &to_cpy) : _cont(to_cpy)
{
}

template <typename Container> PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe<Container> &to_cpy)
{
	if (this != &to_cpy)
	{
		_cont = to_cpy._cont;
	}
	return (*this);
}
template <typename Container> PmergeMe<Container>::~PmergeMe()
{
}

template <typename Container> void PmergeMe<Container>::addElements(const std::string &numbs)
{
	std::istringstream iss(numbs);
	typename Container::value_type num;
	while (iss >> num)
	{
		_cont.push_back(num);
	}
}

template <typename Container> void PmergeMe<Container>::prints()
{
	if (_cont.size() == 0)
		return ;
	for (size_t i = 0; i < (_cont.size() - 1); i++)
	{
		std::cout << _cont[i] << ", ";
	}
	std::cout << _cont.back() << '.' << std::endl;
	return ;
}
template <typename Container> bool PmergeMe<Container>::isSorted()
{
	int	i;

	i = 0;
	if (_cont.size() == 1)
	{
		std::cout << "Already Sorted" << std::endl;
		return (0);
	}
	while (_cont[i + 1])
	{
		if (_cont[i] > _cont[i + 1])
			return (0);
		i++;
	}
	std::cout << "Already Sorted" << std::endl;
	return (1);
}

template <typename Container> bool PmergeMe<Container>::isDouble()
{
	int	i;
	int	j;

	i = 0;
	while (_cont[i])
	{
		j = i + 1;
		while (_cont[j])
		{
			if (_cont[i] == _cont[j])
			{
				std::cout << "Same number twice" << std::endl;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

template <typename Container> void PmergeMe<Container>::sort()
{
	if (isDouble() || isSorted())
		return ;
}
