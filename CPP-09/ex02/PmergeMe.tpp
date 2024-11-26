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
	for (size_t i = 0; i < _cont.size() - 1; ++i)
	{
		if (_cont[i] > _cont[i + 1])
			return (0);
	}
	std::cout << "Already Sorted" << std::endl;
	return (1);
}

template <typename Container> bool PmergeMe<Container>::isDouble()
{
	for (size_t i = 0; i < _cont.size(); ++i)
	{
		for (size_t j = i + 1; j < _cont.size(); ++j)
		{
			if (_cont[i] == _cont[j])
			{
				std::cout << "Same number twice" << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

template <typename Container> void PmergeMe<Container>::pairOrder(int size, int count)
{
	int	npair;
	int count2;

	npair = _cont.size() / size;
	count2 = size;
	if (npair == 0)
	{
		return;
	}
	for (int i = 1; i <= npair; ++i)
	{
		if (_cont[count2 - size + count] > _cont[count2 - 1])
		{
			std::cout << i << std::endl;
			int uplimit = (i) * size - 1;
			int downlimit = size * (i - 1) + (size / 2 - 1);
			int l = 0;
			std::cout << "limits : uplimit = " << uplimit << " downlimit = " << downlimit << std::endl;
			do
			{
				unsigned int tmp = _cont[uplimit];
				_cont[uplimit] = _cont[downlimit];
				_cont[downlimit] = tmp;
				uplimit--;
				downlimit--;
				l++;
			} while ( l != (size / 2));
		}
		count2 += size;
	}
	pairOrder(size * 2, size - 1);
}

template <typename Container> void PmergeMe<Container>::sort()
{
	if (isDouble() || isSorted())
		return ;
	pairOrder(2, 0);
}
