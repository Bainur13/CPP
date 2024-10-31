#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>

class ScalarConverter
{
    public:
        static void convert(const std::string &input);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &src);
        ~ScalarConverter();

        static bool isChar(const std::string &input);
        static bool isInt(const std::string &input);
        static bool isFloat(const std::string &input);
        static bool isDouble(const std::string &input);

        static void printfromChar(const std::string &input);
        static void printfromInt(const std::string &input);
        static void printfromFloat(const std::string &input);
        static void printfromDouble(const std::string &input);
};

#endif