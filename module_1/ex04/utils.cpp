#include "FileManipulation.hpp"
#include <fstream>

void	setters(FileManipulation& obj, char **argv)
{
	obj.set_infile(argv[1]);
	obj.set_be_replaced(argv[2]);
	obj.set_replace(argv[3]);
}

char	open_files(std::ifstream& inFile,
					std::ofstream& outFile,
					FileManipulation& obj)
{
	inFile.open(obj.get_infile());
	outFile.open("outfile.txt", std::ios::out | std::ios::trunc);
	if (!inFile.is_open())
		std::cerr << "Couldn't open input file" << std::endl;
	else if (!inFile.good())
		std::cerr << "Input file doesn't have enough permitions" << std::endl;
	else if (!outFile.is_open())
		std::cerr << "Couldn't open output file" << std::endl;
	else if (!outFile.good())
		std::cerr << "Output file doesn't have enough permitions" << std::endl;
	else
		return (1);
	return (0);
}