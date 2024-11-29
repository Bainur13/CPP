#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &to_cpy) : _cont(to_cpy._cont)
{
}

PmergeMe::PmergeMe(const std::vector<unsigned int> &to_cpy) : _cont(to_cpy)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &to_cpy)
{
	if (this != &to_cpy)
	{
		_cont = to_cpy._cont;
	}
	return (*this);
}
PmergeMe::~PmergeMe()
{
}

void PmergeMe::addElements(const std::string &numbs)
{
	std::istringstream iss(numbs);
	std::vector<unsigned int>::value_type num;
	while (iss >> num)
	{
		_cont.push_back(num);
	}
}

void PmergeMe::prints()
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
bool PmergeMe::isSorted()
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

bool PmergeMe::isDouble()
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

void PmergeMe::makePairAndSortRec(int size)
{
	int	npairs;

	std::vector<std::vector<unsigned int> > vec_cont_tmp;
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

void PmergeMe::swap(int size)
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
void PmergeMe::makePairAndSort()
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
		_odd[_odd.size()].push_back(_cont.back());
		_rankOdd.push_back(2);
	}
	_maxPair = 2;
	makePairAndSortRec(4);
}

void	printVectorOfVectors(const std::vector<std::vector<unsigned int> > &vec)
{
	for (std::vector<std::vector<unsigned int> >::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		for (std::vector<unsigned int>::const_iterator innerIt = it->begin(); innerIt != it->end(); ++innerIt)
		{
			std::cout << *innerIt << " ";
		}
		std::cout << std::endl;
	}
}

void PmergeMe::divide(int size)
{
	int	npairs;

	npairs = _cont.size() / size;
	_vec_cont.resize(npairs);
	for (int i = 0; i < npairs; i++)
	{
		std::vector<unsigned int> temp(_cont.begin() + i * size, _cont.begin()
			+ (i + 1) * size);
		_vec_cont[i] = temp;
	}
}
void PmergeMe::pendInsertion()
{
	int	left;
	int	right;
	int	mid;
    
	for (int i = 2; i < (int)_vec_cont.size(); i += 2)
	{
        left = 0;
		right = i;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (_vec_cont[mid].back() < _vec_cont[i].back())
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
        // for (int j = 0; j < (int)_vec_cont[left].size(); j++)
		//     std::cout << _vec_cont[left][j] <<  " ";
		_vec_cont.insert(_vec_cont.begin() + left, _vec_cont[i]);
		_vec_cont.erase(_vec_cont.begin() + i + 1);
	}
    printVectorOfVectors(_vec_cont);
}

void PmergeMe::insertOdd()
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = _vec_cont.size() - 1;
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
	_vec_cont.insert(_vec_cont.begin() + left, _odd.back());
}

void PmergeMe::makeInsert()
{
	while (_maxPair >= 2)
	{
        _cont.clear();
        for (int i = 0; i < (int)_vec_cont.size(); i++)
		    _cont.insert(_cont.end(), _vec_cont[i].begin(), _vec_cont[i].end());
        // for (int i = 0; i < (int)_cont.size(); i++)
		//     std::cout << _cont[i] <<  " ";
        std::cout << std::endl; 
		divide(_maxPair);
		pendInsertion();
		if (_rankOdd.back() == _maxPair * 2)
		{
            std::cout << "MaxPairrankodd = " << _maxPair << std::endl;
			insertOdd();
			_odd.pop_back();
			_rankOdd.pop_back();
		}
		_maxPair /= 2;
	}
    
}

void PmergeMe::sort()
{
	if (isDouble() || isSorted())
		return ;
	makePairAndSort();
	makeInsert();
}
