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
	std::vector<unsigned int>::value_type num;
	while (iss >> num)
	{
		_cont.push_back(num);
	}
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
template <typename Container> void PmergeMe<Container>::makePairAndSortRec(int size)
{
	int	npairs;

	std::vector<Container> vec_cont_tmp;
	npairs = _vec_cont.size() * size / 2 / size;
	if (npairs == 0)
		return ;
	vec_cont_tmp.resize(npairs);
	for (int i = 0; i < npairs; i++)
	{
		vec_cont_tmp[i] = _vec_cont[i * 2];
		vec_cont_tmp[i].insert(vec_cont_tmp[i].end(), _vec_cont[i * 2
			+ 1].begin(), _vec_cont[i * 2 + 1].end());
	}
	if (_vec_cont.size() % 2 == 1)
	{
		_odd.push_back(_vec_cont.back());
		_rankOdd.push_back(size);
	}
	_vec_cont.resize(npairs);
	_vec_cont = vec_cont_tmp;
	swap(size);
	_maxPair = size;
	makePairAndSortRec(size * 2);
}
template <typename Container> void PmergeMe<Container>::swap(int size)
{
	unsigned int	tmp;
	int				uplimit;
	int				downlimit;
	int				l;

	for (int i = 0; i < (int)_vec_cont.size(); i++)
	{
		if (_vec_cont[i][size / 2 - 1] > _vec_cont[i].back())
		{
			uplimit = size - 1;
			downlimit = (size / 2 - 1);
			l = 0;
			do
			{
				tmp = _vec_cont[i][uplimit];
				_vec_cont[i][uplimit] = _vec_cont[i][downlimit];
				_vec_cont[i][downlimit] = tmp;
				uplimit--;
				downlimit--;
				l++;
			} while (l != (size / 2));
		}
	}
}
template <typename Container> void PmergeMe<Container>::makePairAndSort()
{
	int	npairs;

	npairs = _cont.size() / 2;
	_vec_cont.resize(npairs);
	for (int i = 0; i < npairs; i += 1)
	{
		if (_cont[i * 2] < _cont[i * 2 + 1])
		{
			_vec_cont[i].push_back(_cont[i * 2]);
			_vec_cont[i].push_back(_cont[i * 2 + 1]);
		}
		else
		{
			_vec_cont[i].push_back(_cont[i * 2 + 1]);
			_vec_cont[i].push_back(_cont[i * 2]);
		}
	}
	if (_cont.size() % 2 == 1)
	{
		_odd.push_back(Container(1, _cont.back()));
		_rankOdd.push_back(2);
	}
	_maxPair = 2;
	makePairAndSortRec(4);
}

template <typename Container> void PmergeMe<Container>::divide(int size)
{
	int	npairs;

	npairs = _cont.size() / size;
	_vec_cont.resize(npairs);
	for (int i = 0; i < npairs; i++)
	{
		Container temp(_cont.begin() + i * size, _cont.begin() + (i + 1)
			* size);
		_vec_cont[i] = temp;
	}
}

template <typename Container> void PmergeMe<Container>::setPend()
{
	_pend.clear();
	for (int i = 2; i < (int)_vec_cont.size(); i += 2)
	{
		_pend.push_back(_vec_cont[i]);
		_vec_cont.erase(_vec_cont.begin() + i);
		i -= 1;
	}
	_posPend.clear();
	for (int i = 2; i - 2 < (int)_pend.size(); i++)
	{
		std::string n = "";
		n = i;
		_posPend.push_back(n);
	}
	_posCont.clear();
	_posCont.push_back("1");
	_posCont.push_back("0");
	for (int i = 2; i < (int)_vec_cont.size(); i += 2)
	{
		std::string n = "";
		n = i;
		_posCont.push_back(n);
	}
}

template <typename Container> void PmergeMe<Container>::pendInsertion()
{
	int	left;
	int	right;
	int	mid;
	int	preJacob;
	int	inserted;
	int	jacob;
	int	jacDiff;
	int	nbrtimes;
	int	idx_pend;

	preJacob = jacobsthal(1);
	inserted = 0;
	setPend();
	for (int i = 2;; i++)
	{
		jacob = jacobsthal(i);
		jacDiff = jacob - preJacob;
		if (jacDiff > (int)_pend.size())
			break ;
		nbrtimes = jacDiff;
		idx_pend = jacDiff - 1;
		right = jacob + inserted;
		left = 0;
		while (nbrtimes)
		{
			mid = left + (right - left) / 2;
			if (_pend.empty() == 0
				&& _pend[idx_pend].back() > _vec_cont[mid].back())
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
			if (left == right)
			{
				_vec_cont.insert(_vec_cont.begin() + left, _pend[idx_pend]);
				_pend.erase(_pend.begin() + idx_pend);
				_posPend.erase(_posPend.begin() + idx_pend);
				_posCont.insert(_posCont.begin() + left, "0");
				nbrtimes--;
				idx_pend--;
				right = jacob + inserted;
				left = 0;
			}
		}
		inserted += jacDiff;
	}
	while (_pend.empty() == 0)
	{
		left = 0;
		for (int i = 0; i < (int)_posCont.size(); i++)
		{
			if (atoi(_posCont[i].c_str()) == atoi(_posPend.back().c_str() - 1))
				right = i;
		}
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (_vec_cont[mid].back() < _pend.back().back())
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		while (_vec_cont[left].back() < _pend.back().back())
			left++;
		_vec_cont.insert(_vec_cont.begin() + left, _pend.back());
		_pend.pop_back();
		_posPend.pop_back();
		if (left > (int)_posCont.size())
			_posCont.resize(left);
		else
		_posCont.insert(_posCont.begin() + left, "0");
	}
}

template <typename Container> void PmergeMe<Container>::insertOdd()
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = _vec_cont.size();
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (_vec_cont[mid].back() < _odd.back().back())
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	while (_vec_cont[left].back() < _odd.back().back())
		left++;
	if (left > (int)_vec_cont.size())
		_vec_cont.resize(left);
	_vec_cont.insert(_vec_cont.begin() + left, _odd.back());
}
template <typename Container> void PmergeMe<Container>::makeInsert()
{
	while (_maxPair > 0)
	{
		_cont.clear();
		for (int i = 0; i < (int)_vec_cont.size(); i++)
			_cont.insert(_cont.end(), _vec_cont[i].begin(), _vec_cont[i].end());
		divide(_maxPair);
		pendInsertion();
		if (_rankOdd.empty() == 0 && _rankOdd.back() == _maxPair * 2)
		{
			insertOdd();
			_odd.pop_back();
			_rankOdd.pop_back();
		}
		_maxPair /= 2;
	}
	_cont.clear();
	for (int i = 0; i < (int)_vec_cont.size(); i++)
		_cont.insert(_cont.end(), _vec_cont[i].begin(), _vec_cont[i].end());
}

template <typename Container> bool PmergeMe<Container>::sort(std::string av)
{
	std::clock_t	start = std::clock();
	if (!check_inp(av))
	{
		std::cerr << "Invalid arg" << std::endl;
		return (1);
	}
	addElements(av);
	if (isDouble() || isSorted())
		return (1);
	makePairAndSort();
	makeInsert();
	std::clock_t end = std::clock();
	duration = double(end - start) / CLOCKS_PER_SEC;
	isSorted();
	std::cout << std::endl;
	printVectorOfContainer(_vec_cont);
	return (0);
}
template <typename Container> void PmergeMe<Container>::printVectorOfContainer(const std::vector<Container> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec[i].size(); j++)
		{
			std::cout << vec[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

template <typename Container> Container PmergeMe<Container>::getCont() const
{
	return (_cont);
}
