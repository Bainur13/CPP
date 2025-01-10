#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &input)
{
	if (isMultChar(input))
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	if (isChar(input))
		printfromChar(input);
	else if (isInt(input))
		printfromInt(input);
	else if (isFloat(input))
		printfromFloat(input);
	else if (isDouble(input))
		printfromDouble(input);
	else
		std::cout << "Invalid input" << std::endl;
}

void ScalarConverter::printfromChar(const std::string &input)
{
	char	c;
	int		n;
	float	f;
	double	d;

	if (!isdigit(input.c_str()[0]) && input.size() == 1)
		c = input.c_str()[0];
	else
		c = atoi(input.c_str());
	n = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	if ((n < 32 || n > 126))
		std::cout << "Char : Non displayable" << std::endl;
	else
		std::cout << "Char = '" << c << "'" << std::endl;
	std::cout << "Int = " << n << std::endl;
	std::cout << "Float = " << std::fixed << std::setprecision(1) << f << 'f' << std::endl;
	std::cout << "Double = " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::printfromInt(const std::string &input)
{
	int		n;
	float	f;
	double	d;

	n = atoi(input.c_str());
	f = static_cast<float>(n);
	d = static_cast<double>(n);
	std::cout << "Char = Impossible" << std::endl;
	std::cout << "Int = " << n << std::endl;
	std::cout << "Float = " << std::fixed << std::setprecision(1) << f << 'f' << std::endl;
	std::cout << "Double = " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::printfromFloat(const std::string &input)
{
	char	c;
	int		n;
	float	f;
	double	d;

	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout << "Char : Impossible\nInt : Impossible\n";
		std::cout << "Float : " << input << std::endl;
		std::cout << "Double : ";
		for (int i = 0; i < ((int)input.size() - 1); i++)
			std::cout << input[i];
		std::cout << std::endl;
		return ;
	}
	f = strtof(input.c_str(), NULL);
	c = static_cast<char>(f);
	n = static_cast<int>(f);
	d = static_cast<double>(f);
	if (n > 31 && n < 127)
		std::cout << "Char : '" << c << "'" << std::endl;
	else if (n >= CHAR_MIN && n <= CHAR_MAX)
		std::cout << "Char : Non displayable" << std::endl;
	else
		std::cout << "Char : Impossible" << std::endl;
	if (d > 2147483647 || d < -2147483648)
		std::cout << "Int : Impossible" << std::endl;
	else
		std::cout << "Int : " << n << std::endl;
	if ((abs)(f - n) < EPSILON)
	{
		std::cout << "Float = " << std::fixed << std::setprecision(1) << f << 'f' << std::endl;
		std::cout << "Double = " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else
	{
		std::cout << "Float : " << f << "f" << std::endl;
		std::cout << "Double : " << d << std::endl;
	}
}

void ScalarConverter::printfromDouble(const std::string &input)
{
    char	c;
	int		n;
	float	f;
	double	d;

	if (input == "-inf" || input == "+inf" || input == "nan")
	{
		std::cout << "Char : Impossible\nInt : Impossible\n";
		std::cout << "Float : " << input << "f" <<std::endl;
		std::cout << "Double : " << input << std::endl;
		return ;
	}
	d = strtod(input.c_str(), NULL);
	c = static_cast<char>(d);
	n = static_cast<int>(d);
	f = static_cast<float>(d);
	if (n > 31 && n < 127)
		std::cout << "Char : '" << c << "'" << std::endl;
	else if (n >= CHAR_MIN && n <= CHAR_MAX)
		std::cout << "Char : Non displayable" << std::endl;
	else
		std::cout << "Char : Impossible" << std::endl;
	if (d > 2147483647 || d < -2147483648)
		std::cout << "Int : Impossible" << std::endl;
	else
		std::cout << "Int : " << n << std::endl;
	if ((abs)(d - n) < EPSILON)
	{
		std::cout << "Float = " << std::fixed << std::setprecision(1) << f << 'f' << std::endl;
		std::cout << "Double = " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else
	{
		std::cout << "Float : " << f << "f" << std::endl;
		std::cout << "Double : " << d << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string &input)
{
	int	n;

	if (input.length() > 3 && (input.length() > 4 && input.c_str()[0] == '-'))
	{
		return (false);
	}
	for (int i = 0; i < (int)input.size(); i++)
	{
		if (!isdigit(input.c_str()[i]))
		{
			if (input.length() == 1 && isprint(input.c_str()[0]))
				return (true);
			break ;
		}
	}
	n = atoi(input.c_str());
	if (n < CHAR_MIN || n > CHAR_MAX)
	{
		return (false);
	}
	return (true);
}

bool ScalarConverter::isInt(const std::string &input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i])
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	long l = strtol(input.c_str(), NULL, 10);
	if (l > 2147483647 || l < -2147483648)
		return (false);
	return (true);
}

bool ScalarConverter::isFloat(const std::string &input)
{
	int		i;
	bool	deci;

	i = 0;
	deci = false;
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	while (isspace(input[i]))
		i++;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (!isdigit(input[i]))
		return (false);
	i++;
	while (input[i])
	{
		if (input[i] == '.')
		{
			if (deci == false)
				deci = true;
			else
				return (false);
			i++;
		}
		if (input[i] == 'f')
			break ;
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	if (input[i] != 'f')
		return (false);
	i++;
	while (isspace(input[i]))
		i++;
	if (i != (int)input.size())
		return (false);
	return (true);
}

bool ScalarConverter::isDouble(const std::string &input)
{
	int		i;
	bool	deci;

	i = 0;
	deci = false;
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	while (isspace(input[i]))
		i++;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (!isdigit(input[i]))
		return (false);
	i++;
	while (input[i])
	{
		if (input[i] == '.')
		{
			if (deci == false)
				deci = true;
			else
				return (false);
			i++;
		}
		if (!isdigit(input[i]))
			break ;
		i++;
	}
	while (input[i])
	{
		if (!isspace(input[i]))
			return (false);
		i++;
	}
	return (true);
}

bool isStrDigit(const std::string &input)
{
	int	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i])
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
}

bool ScalarConverter::isMultChar(const std::string &input)
{
	if (input.size() == 1)
		return (false);
	if (isStrDigit(input))
		return (false);
	return (true);
}
