#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &to_cpy)
{
	_stackNumbers = to_cpy._stackNumbers;
	_op = to_cpy._op;
}

RPN &RPN::operator=(const RPN &to_cpy)
{
	if (this != &to_cpy)
	{
		_stackNumbers = to_cpy._stackNumbers;
		_op = to_cpy._op;
	}
	return (*this);
}

RPN::~RPN()
{
}

void RPN::handleString(std::string str)
{
	for (int i = 0; i <= (int)str.length(); i++)
	{
		if ((handleNumber(str[i]) || handleOperator(str[i])) && (str[i
				+ 1] == ' ' || str[i + 1] == '\0'))
		{
			execCalcul();
			_op = 'p';
		}
		else if (isspace(str.c_str()[i]) || str[i] == '\0')
			continue ;
		else
		{
			// std::cout << i << std::endl;
			// std::cout << "Invalid Character " << str[i] << std::endl;
			throwError();
		}
	}
	if (_stackNumbers.size() > 1)
	{
		// std::cout << "Too much char at the end" << std::endl;
		throwError();
	}
	std::cout << _stackNumbers.top() << std::endl;
}

bool RPN::handleNumber(char c)
{
	if (isdigit(c))
	{
		_stackNumbers.push(c - '0');
		return (1);
	}
	else
		return (0);
}

int RPN::handleOperator(char c)
{
	char	sym[] = {'+', '-', '/', '*'};

	for (int i = 0; i < 4; i++)
	{
		if (sym[i] == c && _stackNumbers.size() >= 1)
		{
			_op = c;
			return (i + 1);
		}
	}
	return (0);
}

void RPN::execCalcul()
{
	long	n;

	if (_stackNumbers.size() < 2 || _op == 'p')
		return ;
	switch (handleOperator(_op))
	{
	case 1:
		n = _stackNumbers.top();
		_stackNumbers.pop();
		n = n + _stackNumbers.top();
		_stackNumbers.pop();
		_stackNumbers.push(n);
		break ;
	case 2:
		n = _stackNumbers.top();
		_stackNumbers.pop();
		n = _stackNumbers.top() - n;
		_stackNumbers.pop();
		_stackNumbers.push(n);
		break ;
	case 3:
		n = _stackNumbers.top();
		_stackNumbers.pop();
		n = _stackNumbers.top() / n;
		_stackNumbers.pop();
		_stackNumbers.push(n);
		break ;
	case 4:
		n = _stackNumbers.top();
		_stackNumbers.pop();
		n = _stackNumbers.top() * n;
		_stackNumbers.pop();
		_stackNumbers.push(n);
		break ;
	default:
		throwError();
	}
}

void RPN::throwError()
{
	throw std::runtime_error("Error");
}
