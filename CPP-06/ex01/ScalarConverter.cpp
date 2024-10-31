#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
    (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string str)
{
    printChar(str);
    printInt(str);
    printFloat(str);
    printDouble(str);
}

bool ScalarConverter::CheckisChar(std::string str)
{
    if (str == "nan" || str == "nanf" || str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf")
    {
        std::cout << "Char: impossible" << std::endl;
        return false;
    }
    double a = atof(str.c_str());
    if (a < CHAR_MIN || a > CHAR_MAX)
    {
        std::cout << "Char: Above limits" << std::endl;
        return false;
    }
    if (a < 32 || a > 126)
    {
        std::cout << "Char: Non displayable" << std::endl;
        return false;
    }
    return true;
}

void ScalarConverter::printChar(std::string str)
{
    double a;

    if (CheckisChar(str))
    {
        a = atof(str.c_str());
        std::cout << "Char: '" << static_cast<char>(a) << "'" << std::endl;
    }
}

bool ScalarConverter::CheckisInt(std::string str)
{
    if (str == "nan" || str == "nanf" || str == "-inff" || str == "+inff" || str == "-inf" || str == "+inf")
    {
        std::cout << "Int: impossible" << std::endl;
        return false;
    }
    double a = atof(str.c_str());
    if (a < INT_MIN || a > INT_MAX)
    {
        std::cout << "Int: Above limits" << std::endl;
        return false;
    }
    return true;
}

void ScalarConverter::printInt(std::string str)
{
    double a;

    if (CheckisInt(str))
    {
        a = atof(str.c_str());
        std::cout << "Int: " << static_cast<int>(a) << std::endl;
    }
}

bool ScalarConverter::CheckisFloat(std::string str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
    {
        std::cout << "Float: " << str << "f" << std::endl;
        return false;
    }
    if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        std::cout << "Float: " << str << std::endl;
        return false;
    }
    double a = atof(str.c_str());
    if (a < -FLT_MAX || a > FLT_MAX)
    {
        std::cout << "Float: Above limits" << std::endl;
        return false;
    }
    return true;
}

void ScalarConverter::printFloat(std::string str)
{
    float a;

    if (CheckisFloat(str))
    {
        a = atof(str.c_str());
        std::cout << "Float: " << a << "f" << std::endl;
    }
}


bool ScalarConverter::CheckisDouble(std::string str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
    {
        std::cout << "Double: " << str << std::endl;
        return false;
    }
    if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        str.erase(str.end() - 1);
        std::cout << "Double: " << str << std::endl;
        return false;
    }
    double a = atof(str.c_str());
    if (a < -DBL_MAX || a > DBL_MAX)
    {
        std::cout << "Double: Above limits" << std::endl;
        return false;
    }
    return true;
}

void ScalarConverter::printDouble(std::string str)
{
    double a;

    if (CheckisDouble(str))
    {
        a = atof(str.c_str());
        std::cout << "Double: " << static_cast<double>(a) << std::endl;
    }
}


