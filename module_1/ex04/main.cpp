#include "FileManipulation.hpp"
#include <fstream>

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
	if (open_files(inFile, outFile, obj))
	{
		content = replace(obj, inFile);
		if (content[0] == '\0')
			std::cout << "Empty file" << std::endl;
		else
			outFile << content << std::endl;
	}

	if (outFile.is_open()) outFile.close();
	if (inFile.is_open()) inFile.close();
}
