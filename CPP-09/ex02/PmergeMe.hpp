#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstdlib>
# include <deque>
# include <iostream>
# include <sstream>
# include <string>
# include <vector>

class PmergeMe
{
  public:
	PmergeMe();
	PmergeMe(const PmergeMe &to_cpy);

	PmergeMe(const std::vector<unsigned int> &to_cpy);

	PmergeMe &operator=(const PmergeMe &to_cpy);

	~PmergeMe();

	void addElements(std::string const &numbs);
	void sort();

	void prints();

  private:
	std::vector<unsigned int> _cont;
	std::vector<std::vector<unsigned int> > _vec_cont;
	std::vector<std::vector<unsigned int> > _odd;
	std::vector<int> _rankOdd;
	std::vector<std::string> _pos;
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
};

void	printVectorOfVectors(const std::vector<std::vector<unsigned int> > &vec);


#endif
