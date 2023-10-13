#include <iostream>
#include <fstream>
#include "FileManipulation.hpp"

std::string	replace(FileManipulation& obj, std::ifstream& inFile)
{
	std::string	line;
	size_t		position;
	std::string	content;

	while(std::getline(inFile, line))
	{
		while (line.find(obj.get_be_replaced()) != std::string::npos)
		{
			position = line.find(obj.get_be_replaced());
			line.erase(position, obj.get_be_replaced().length());
			line.insert(position, obj.get_replace());
		}
		content += line;
		content.insert(content.length(), "\n");
	}
	return (content);
}

void	setters(FileManipulation& obj, char **argv)
{
	obj.set_infile(argv[1]);
	obj.set_be_replaced(argv[2]);
	obj.set_replace(argv[3]);
}

char	check_files(std::ifstream& inFile, std::ofstream& outFile)
{
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

int	main(int argc, char **argv)
{
	FileManipulation	obj;
	std::ofstream		outFile;
	std::ifstream		inFile;
	std::string			content;

	if (argc != 4){
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}

	setters(obj, argv);
	inFile.open(obj.get_infile());
	outFile.open("outfile.txt", std::ios::out | std::ios::trunc);

	if (!check_files(inFile, outFile))
		return (0);

	content = replace(obj, inFile);
	if (content[0] == '\0')
	{
		std::cout << "Empty file" << std::endl;
		return (0);
	}
	else
		outFile << content << std::endl;

	if (outFile.is_open()) outFile.close();
	if (inFile.is_open()) inFile.close();
}
