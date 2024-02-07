#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdlib.h>
#include <cfloat>
#include <climits>

#include <iomanip>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};
class ScalarConverter
{
	public:
		static void convert(std::string &input);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &obj);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &obj);
};

#endif
