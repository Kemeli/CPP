#include <iostream>
#include <fstream>
#include "FileManipulation.hpp"

int	main(int argc, char **argv)
{
	FileManipulation	obj;
	std::string			line;
	std::ofstream		outFile;
	std::ifstream		inFile;
	size_t				position;

	if (argc != 4){
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}

	obj.set_infile(argv[1]);

	inFile.open(obj.get_infile());

	if (inFile.is_open())
	{
		obj.set_be_replaced(argv[2]);
		obj.set_replace(argv[3]);
		outFile.open("outfile.txt", std::ios::out | std::ios::trunc);
		if (outFile.is_open())
		{
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
		else
			std::cerr << "coudn't open output file" << std::endl;
		inFile.close();
	}
	else
		std::cerr << "coudn't open input file" << std::endl;
}

// int	main(int argc, char **argv)
// {
// 	std::string		line;
// 	std::ifstream	inFile;
// 	std::ofstream	outFile;

// 	size_t			position;
// 	std::string		first_parameter;
// 	std::string		sec_parameter;

// 	if (argc != 4){
// 		std::cout << "Wrong number of arguments" << std::endl;
// 		return (0);
// 	}

// 	first_parameter = argv[2];
// 	sec_parameter = argv[3];

// 	inFile.open(argv[1], std::ios::in);
// 	if (inFile.is_open())
// 	{
// 		outFile.open("outfile.txt", std::ios::out | std::ios::trunc);
// 		if (outFile.is_open())
// 		{
// 			while(std::getline(inFile, line))
// 			{
// 				while (line.find(first_parameter) != std::string::npos)
// 				{
// 					position = line.find(first_parameter);
// 					line.erase(position, first_parameter.length());
// 					line.insert(position, sec_parameter);
// 				}
// 				outFile << line << std::endl;
// 			}
// 			outFile.close();
// 		}
// 		else
// 			std::cerr << "coudn't open output file" << std::endl;
// 		inFile.close();
// 	}
// 	else
// 		std::cerr << "coudn't open input file" << std::endl;
// }
