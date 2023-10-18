#include "FileManipulation.hpp"
#include <fstream>

void	setters(FileManipulation& obj, char **argv)
{
	obj.set_infile(argv[1]);
	obj.set_be_replaced(argv[2]);
	obj.set_replace(argv[3]);
}

char	output_file(std::ofstream& outFile, FileManipulation& obj)
{
	std::string	strout;
	std::string	strin;

	strin = obj.get_infile();
	strout = strin.append(".replace");
	outFile.open(strout.data(), std::ios::out | std::ios::trunc);

	if (!outFile.is_open())
		std::cerr << "Couldn't open output file" << std::endl;
	else if (!outFile.good())
		std::cerr << "Output file doesn't have enough permitions" << std::endl;
	else
		return (1);
	return (0);
}

char	input_file(std::ifstream& inFile, FileManipulation& obj)
{
	std::string	strin;

	strin = obj.get_infile();
	inFile.open(strin.data());

	if (!inFile.is_open())
		std::cerr << "Couldn't open input file" << std::endl;
	else if (!inFile.good())
		std::cerr << "Input file doesn't have enough permitions" << std::endl;
	else
		return (1);
	return (0);
}
