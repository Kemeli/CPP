
#include <iostream>
#include <fstream>

// int	main(int argc, char **argv)
int	main()
{
	std::string		line;
	std::ifstream	inFile;
	std::ofstream	outFile;

	std::string		p1 = "file";
	std::string		p2 = "MACARRÃO";
	size_t			position;

	// if (argc != 4){
	// 	std::cout << "Wrong number of arguments" << std::endl;
	// 	return (0);
	// }

	inFile.open("infile.txt", std::ios::in);
	if (inFile.is_open())
	{
		outFile.open("outfile.txt", std::ios::out | std::ios::trunc);
		if (outFile.is_open())
		{
			while(std::getline(inFile, line))
			{
				while (line.find(p1) != std::string::npos)
				{
					position = line.find(p1);
					line.erase(position, p1.length());
					line.insert(position, p2);
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
