#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>


class Span
{
    public :
        Span(unsigned int N);
        Span();
        Span (const Span &to_cpy);
        Span &operator=(const Span &to_cpy);
        ~Span();

        void addNumber(int number);

        template <typename Iterator>
		void	addNumbers(Iterator begin, Iterator end)
		{
			while (begin != end)
			{
                std::cout << "mmmh" << std::endl;
				addNumber(*begin);
				begin++;
			}
		}

        unsigned int shortestSpan();
        unsigned int longestSpan();

    private :
        
        void throwTooMuchNumbers();
        void throwNotEnoughNumbers();
        
        unsigned int _N;
        std::vector<int> _vec;
};

#endif
