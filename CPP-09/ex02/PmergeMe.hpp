#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cmath>
# include <cstdlib>
# include <deque>
# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <chrono>

template <typename Container = std::vector<unsigned int> > class PmergeMe
{
  public:
	PmergeMe();
	PmergeMe(const PmergeMe &to_cpy);

	PmergeMe(const Container &to_cpy);

	PmergeMe &operator=(const PmergeMe &to_cpy);

	~PmergeMe();

	void addElements(std::string const &numbs);
	bool sort(std::string av, std::string type);
	std::chrono::duration<double> duration;
	Container getCont() const;

  private:
	Container _cont;
	std::vector<Container> _vec_cont;
	std::vector<Container> _odd;
	std::vector<Container> _pend;
	std::vector<int> _rankOdd;
	std::vector<std::string> _posCont;
	std::vector<std::string> _posPend;

	int _maxPair;
	bool isSorted();
	bool isDouble();
	void makePairAndSort();
	void makePairAndSortRec(int size);
	void makeInsert();
	void divide(int size);
	void pendInsertion();
	void insertOdd();
	void swap(int size);
	void printVectorOfContainer(const std::vector<Container> &vec);

	void setPend();
};

int	jacobsthal(int n);
bool check_inp(std::string numbs);

# include "PmergeMe.tpp"

#endif
