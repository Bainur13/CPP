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
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &input)
{
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
    std::cout << input << std::endl;
    std::cout << "CHAR" << std::endl;
}

void ScalarConverter::printfromInt(const std::string &input)
{
    std::cout << input << std::endl;
    std::cout << "Int" << std::endl;
}

void ScalarConverter::printfromFloat(const std::string &input)
{
    std::cout << input << std::endl;
    std::cout << "Float" << std::endl;
}

void ScalarConverter::printfromDouble(const std::string &input)
{
    std::cout << input << std::endl;
    std::cout << "Double" << std::endl;
}

bool ScalarConverter::isChar(const std::string &input)
{
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
        return true;
    return false;
}

bool ScalarConverter::isInt(const std::string &input)
{
    int i = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;
    while (input[i])
    {
        if (!isdigit(input[i]))
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string &input)
{
    int i = 0;
    bool deci = false;

    if (input == "-inff" || input == "+inff" || input == "nanf")
        return (true);
    while (isspace(input[i]))
        i++;
    if (input[i] == '+' || input[i] == '-')
        i++;
    if (!isdigit(input[i]))
        return false;
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
            break;
        if (!isdigit(input[i]))
            return false;
        i++;
    }
    if (input[i] != 'f')
        return false;
    i++;
    while (isspace(input[i]))
        i++;
    if (i != (int)input.size())
        return (false);
    return (true);
}

bool ScalarConverter::isDouble(const std::string &input)
{
    int i = 0;
    bool deci = false;
    
    if (input == "-inf" || input == "+inf" || input == "nan")
        return (true);
    while (isspace(input[i]))
        i++;
    if (input[i] == '+' || input[i] == '-')
        i++;
    if (!isdigit(input[i]))
        return false;
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
            break;
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