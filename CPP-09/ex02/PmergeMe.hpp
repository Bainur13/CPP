#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>

template <typename Container = std::vector<unsigned int>>

class PmergeMe
{
  public:
	PmergeMe<Container>(Container T);
	PmergeMe<Container>(const PmergeMe &to_cpy);

	PmergeMe<Container>(const Container &to_cpy);

	PmergeMe &operator=(const PmergeMe &to_cpy);

	~PmergeMe();

  private:
    PmergeMe<Container>();
	Container _cont;
};

#endif
