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

static bool is_allnum(std::string input)
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

static bool is_decimal_num(std::string input)
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

static void handle_double(std::string input, int precision)
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
	if (num < INT_MIN || num > INT_MAX || !is_decimal_num(input))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(precision)
		 << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << num << std::endl;
}

static void handle_float(std::string input, int precision)
{
	double num = std::strtof(input.c_str(), NULL);
	std::cout << "char: ";
	if (num < 0 || num > 127 || !std::isdigit(input[0]))
		std::cout << "impossible" << std::endl;
	else if (num < 32 || num == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
	if (num < INT_MIN || num > INT_MAX  || !is_decimal_num(input))
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout << "float: " << std::fixed << std::setprecision(precision)
			<< num << "f" << std::endl;
		std::cout << "double: "<< std::fixed << std::setprecision(precision)
			<< static_cast<double>(num) << std::endl;
	}
	else if (num < -FLT_MAX || num > FLT_MAX)
	{
		std::cout << "float : impossible\n";
		std::cout << "double : impossible\n";
	}
	else
	{
		std::cout << "float: " << std::fixed << std::setprecision(precision)
			<< num << "f" << std::endl;
		std::cout << "double: "<< std::fixed << std::setprecision(precision)
			<< static_cast<double>(num) << std::endl;
	}
}

static void handle_int(std::string input, int precision)
{
	long num = strtol(input.c_str(), NULL, 10);
	
	std::cout << "char: ";
	if (num < 0 || num > 127)
		std::cout << "impossible" << std::endl;
	else if (num < 32 || num == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
	if (num < INT_MIN || num > INT_MAX)
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << num << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(precision)
			<< static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(precision)
			<< static_cast<double>(num) << std::endl;
	}
}

static void handle_char(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static int set_type(std::string input)
{
	int len = input.length();
	int type = -1;

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
	return (type);
}

void ScalarConverter::convert(std::string &input)
{
	int type = set_type(input);
	size_t pos = input.find('.');
	int precision = 1;

	if (pos != std::string::npos)
	{
		precision--;
		while (input[++pos] && input[pos] != 'f')
			precision++;
	}
	if (type == CHAR)
		handle_char(input[0]);
	else if (type == INT)
		handle_int(input, precision);
	else if (type == FLOAT)
		handle_float(input, precision);
	else if (type == DOUBLE)
		handle_double(input, precision);
	else if (type == UNKNOWN)
		std::cout << "Error: Unknown type" << std::endl;
	else
		std::cout << "Error: Unknown type" << std::endl;
}
