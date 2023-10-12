#include <iostream>
#include <fstream>
#include "FileManipulation.hpp"

void	replace(FileManipulation& obj,
				std::ifstream& inFile,
				std::ofstream& outFile
		)
{
	std::string	line;
	size_t		position;

	

	while(std::getline(inFile, line))
	{
		while (line.find(obj.get_be_replaced()) != std::string::npos)
		{
			position = line.find(obj.get_be_replaced());
			line.erase(position, obj.get_be_replaced().length());
			line.insert(position, obj.get_replace());
		}
		outFile << line << std::endl;
	}
	outFile.close();
}

void	setters(FileManipulation& obj, char **argv)
{
	obj.set_infile(argv[1]);
	obj.set_be_replaced(argv[2]);
	obj.set_replace(argv[3]);
}

int	main(int argc, char **argv)
{
	FileManipulation	obj;
	std::ofstream		outFile;
	std::ifstream		inFile;

	if (argc != 4){
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}

	setters(obj, argv);
	inFile.open(obj.get_infile());

	if (inFile.is_open())
	{
		outFile.open("outfile.txt", std::ios::out | std::ios::trunc);
		if (outFile.is_open())
			replace(obj, inFile, outFile);
		else
			std::cerr << "coudn't open output file" << std::endl;
		inFile.close();
	}
	else
		std::cerr << "coudn't open input file" << std::endl;
}
