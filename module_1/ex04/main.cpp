#include "FileManipulation.hpp"
#include <fstream>


int	main(int argc, char **argv)
{
	FileManipulation	obj;
	std::ofstream		outFile;
	std::ifstream		inFile;
	std::string			content;

	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}
	setters(obj, argv);
	if (input_file(inFile, obj))
	{
		content = replace(obj, inFile);
		if (content.empty())
		{
			std::cout << "Empty file" << std::endl;
			return (0);
		}
		if (output_file(outFile, obj))
			outFile << content << std::endl;
	}
	if (outFile.is_open()) outFile.close();
	if (inFile.is_open()) inFile.close();
}
