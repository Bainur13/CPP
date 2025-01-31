#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &to_cpy) : _N(to_cpy._N), _vec(to_cpy._vec)
{
}

Span &Span::operator=(const Span &to_cpy)
{
    if (this != &to_cpy)
    {
        _vec.clear();
        _vec = to_cpy._vec;
        _N = to_cpy._N;
    }
    return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int numb)
{
    if (_vec.size() == _N)
        throwTooMuchNumbers();
    else
        _vec.push_back(numb);
}

void Span::addNumbers(int begin, int end)
{
    while (begin != end)
    {
        addNumber(begin);
        begin++;
    }
}

unsigned int Span::shortestSpan()
{
    unsigned int shortest;

    shortest = UINT_MAX;
    if (_vec.size() < 2)
        throwNotEnoughNumbers();
    std::vector<int> vec2 = _vec;
    std::sort(vec2.begin(), vec2.end());
    for (std::vector<int>::iterator it_b = vec2.begin(); it_b != vec2.end() - 1; it_b++)
    {
        unsigned int diff = static_cast<unsigned int>(*(it_b + 1) - *it_b);
        if (diff == 0)
            return (0);
        if (diff < shortest)
            shortest = diff;
    }
    return (shortest);
}

unsigned int Span::longestSpan()
{
    if (_vec.size() < 2)
        throwNotEnoughNumbers();
    std::vector<int> _vec2 = _vec;
    std::sort(_vec2.begin(), _vec2.end());
    return (_vec2.back() - _vec2.front());
}

Span::Span() : _N(0) {}

void Span::throwTooMuchNumbers()
{
    throw std::out_of_range("Span is full.");
}

void Span::throwNotEnoughNumbers()
{
    throw std::out_of_range("Not enough number in Span.");
}
