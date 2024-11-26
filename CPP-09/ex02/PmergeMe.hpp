#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstdlib>
# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <deque>

template <typename Container = std::vector<unsigned int> >

class PmergeMe
{
  public:
	PmergeMe();
	PmergeMe(const PmergeMe &to_cpy);

	PmergeMe(const Container &to_cpy);

	PmergeMe &operator=(const PmergeMe &to_cpy);

	~PmergeMe();

	void addElements(std::string const &numbs);
	void sort();
	
	void prints();

  private:
	Container _cont;
	bool isSorted();
	bool isDouble();
	void pairOrder(int size, int count);
};

# include "PmergeMe.tpp"

#endif
