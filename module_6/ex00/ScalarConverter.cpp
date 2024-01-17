#include "ScalarConverter.hpp"
#include <cctype>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &obj)
{
	*this = obj;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &obj)
{
	(void)obj;
	return (*this);
}

bool is_allnum(std::string input)
{
	int size = input.size();
	for (int i = 0; i < size; i++)
	{
		if (input[i] == '-' && i == 0)
			continue;
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

char is_decimal_num(std::string input)
{
	int dot = 0;
	int len = input.length();
	for (int i = 0; i < len; i++)
	{
		if (input[i] == '-' && i == 0)
			continue;
		if (i == len - 1 && input[i] == 'f')
			break;
		if (!std::isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			return (0);
		if (input[i] == '.')
			dot++;
		if (dot > 1)
			return (0);
	}
	return (1);
}

void ScalarConverter::convert(std::string &input)
{
	int type = -1;
	size_t pos = input.find('.');
	int precision = 1;

	if (pos != std::string::npos)
	{
		precision--;
		while (input[++pos] && input[pos] != 'f')
			precision++;
	}

	int len = input.length();
	if (len == 1 && !std::isdigit(input[0]))
		type = CHAR;
	else if (is_allnum(input))
		type = INT;
	else if (len > 1 && is_decimal_num(input) && input[len - 1] == 'f')
		type = FLOAT;
	else if (len > 1 && is_decimal_num(input))
		type = DOUBLE;
	else if (input == "-inff" || input == "+inff" || input == "nanf")
		type = FLOAT;
	else if (input == "-inf" || input == "+inf" || input == "nan")
		type = DOUBLE;
	else
		type = UNKNOWN;

	if (type == CHAR)
	{
		std::cout << "char: '" << input[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
	}
	else if (type == INT)
	{
		int num = atoi(input.c_str());
		std::cout << "char: ";
		if (num < 0 || num > 127)
			std::cout << "impossible" << std::endl;
		else if (num < 32 || num == 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		std::cout << "int: " << num << std::endl;
		std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
	}
	else if (type == FLOAT)
	{
		float num = atof(input.c_str());
		std::cout << "char: ";
		if (num < 0 || num > 127 || !std::isdigit(input[0]))
			std::cout << "impossible" << std::endl;
		else if (num < 32 || num == 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
		std::cout << "int: ";
		if (num < INT_MIN || num > INT_MAX)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(num) << std::endl;

		std::cout << std::fixed << std::setprecision(precision) << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
	}
	else if (type == DOUBLE)
	{
		double num = atof(input.c_str());
		std::cout << "char: ";
		if (num < 0 || num > 127 || !std::isdigit(input[0]))
			std::cout << "impossible" << std::endl;
		else if (num < 32 || num == 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;

		std::cout << "int: ";
		if (num < INT_MIN || num > INT_MAX)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(num) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << num << std::endl;
	}
	else if (type == UNKNOWN)
		std::cout << "Error: Unknown type" << std::endl;
	else
		std::cout << "Error: Unknown type" << std::endl;
}
