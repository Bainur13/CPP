#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cfloat>

class ScalarConverter
{
    public:
        static void convert(std::string str);
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &src);
        ScalarConverter &operator=(ScalarConverter const &rhs);
        ~ScalarConverter();

        static bool CheckisChar(std::string str);
        static bool CheckisInt(std::string str);
        static bool CheckisFloat(std::string str);
        static bool CheckisDouble(std::string str);

        static void printChar(std::string str);
        static void printInt(std::string str);
        static void printFloat(std::string str);
        static void printDouble(std::string str);
        static void printSpecial(std::string str);
};

#endif