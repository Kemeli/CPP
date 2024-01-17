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
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &other);

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
			int _type;
			char _char;
			int _int;
			float _float;
			double _double;


			// void _set_type(std::string input);
};

#endif
