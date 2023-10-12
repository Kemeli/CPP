
#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	std::string		line;
	std::ifstream	inFile;
	std::ofstream	outFile;

	size_t			position;
	std::string		first_parameter;
	std::string		sec_parameter;

	if (argc != 4){
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}

	first_parameter = argv[2];
	sec_parameter = argv[3];


	inFile.open("infile.txt", std::ios::in);
	if (inFile.is_open())
	{
		outFile.open("outfile.txt", std::ios::out | std::ios::trunc);
		if (outFile.is_open())
		{
			while(std::getline(inFile, line))
			{
				while (line.find(first_parameter) != std::string::npos)
				{
					position = line.find(first_parameter);
					line.erase(position, first_parameter.length());
					line.insert(position, sec_parameter);
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
