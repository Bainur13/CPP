#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cfloat>
# include <climits>
# include <cstdlib>
# include <stdlib.h>
# include <iomanip>
# include <iostream>
# include <string>


#define EPSILON 0.000001
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
