#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Pass a valid argument" << std::endl;
		return (1);
	}
	std::string input = argv[1];
	ScalarConverter::convert(input);
	return (0);
}
