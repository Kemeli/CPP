#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdlib.h>
#include <cfloat>
#include <climits>

#include <iomanip>

class ScalarConverter
{
	public:

		static void convert(std::string &input);

		enum Type
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			UNKNOWN
		};

		private:
			ScalarConverter();
			ScalarConverter(ScalarConverter const &other);
			~ScalarConverter();
			ScalarConverter &operator=(ScalarConverter const &other);

			static int _set_type(std::string input);
			static bool _is_allnum(std::string input);
			static bool _is_decimal_num(std::string input);
			static void _handle_char(char c);
			static void _handle_int(std::string input);
			static void _handle_float(std::string input, int precision);
			static void _handle_double(std::string input, int precision);
};

#endif
