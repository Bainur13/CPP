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

template <typename Container> void PmergeMe<Container>::pairOrder(int size,
	int count, std::vector<Container> &pairs)
{
	int				npair;
	int				index;
	int				size_prec;
	Container		pend;
	Container		odd;
	int				uplimit;
	int				downlimit;
	unsigned int	tmp;
	int				l;

	size_prec = size / 2;
	npair = pairs.size() / 2;
	index = 0;
	count++;
	if (npair == 0)
		return ;
	for (int i = 0; i < (int)pairs.size(); i++)
	{
		if (pairs[i][size_prec / 2 - 1] > pairs[i].back())
		{
			uplimit = size_prec - 1;
			downlimit = (size_prec / 2 - 1);
			l = 0;
			std::cout << "limits : uplimit = " << uplimit << " downlimit = " << downlimit << std::endl;
			do
			{
				tmp = pairs[i][uplimit];
				pairs[i][uplimit] = pairs[i][downlimit];
				pairs[i][downlimit] = tmp;
				uplimit--;
				downlimit--;
				l++;
			} while (l != (size_prec / 2));
		}
	}
	std::cout << "size of pairs : " << size_prec << std::endl;
	for (int l = 0; l < (int)pairs.size(); l++)
	{
		std::cout << "pair number : " << l << " = ";
		for (unsigned int i = 0; i < pairs[l].size(); i++)
		{
			std::cout << pairs[l][i] << ' ';
		}
		std::cout << std::endl;
	}
	std::vector<Container> npairs(npair);
	for (int i = 0; i < npair * 2; i += 2)
	{
		npairs[index] = pairs[i];
		npairs[index].insert(npairs[index].end(), pairs[i + 1].begin(), pairs[i
			+ 1].end());
		index++;
	}
	std::cout << std::endl;
	pairOrder(size * 2, size - 1, npairs);
	if (pairs.size() % 2 == 1)
		odd = pairs.back();
	if (npair % 2 == 1)
	{
		pend = npairs.back();
		npairs.pop_back();
	}
	
}

template <typename Container> void PmergeMe<Container>::recursiPairVec()
{
	int	npair;
	int	vecNum;
	int	index;

	npair = _cont.size() / 2;
	vecNum = 0;
	index = 0;
	std::vector<Container> pairs(npair);
	for (int i = 0; i < npair; ++i)
	{
		while (index < (i + 1) * 2 && index < (int)_cont.size())
		{
			pairs[vecNum].push_back(_cont[index]);
			index++;
		}
		vecNum++;
	}
	// for (int l = 0; l < npair; l++)
	// {
	// 	std::cout << "pair number : " << l << " = ";
	// 	for (unsigned int i = 0; i < pairs[l].size(); i++)
	// 	{
	// 		std::cout << pairs[l][i] << ' ';
	// 	}
	// 	std::cout << std::endl;
	// }
	pairOrder(4, 1, pairs);
}
template <typename Container> void PmergeMe<Container>::sort()
{
	if (isDouble() || isSorted())
		return ;
	recursiPairVec();
}
