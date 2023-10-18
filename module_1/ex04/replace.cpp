#include "FileManipulation.hpp"
#include <fstream>

std::string	replace(FileManipulation& obj, std::ifstream& inFile)
{
	std::string	line;
	size_t		position;
	std::string	content;
	std::string	replace;
	std::string	replaced;
	char		equal;

	replaced = obj.get_be_replaced();
	replace = obj.get_replace();

	equal = 0;
	if (replaced == replace)
		equal = 1;

	while(std::getline(inFile, line))
	{
		while (!equal && line.find(replaced) != std::string::npos)
		{
			position = line.find(replaced);
			line.erase(position, replaced.length());
			line.insert(position, replace);
		}
		content += line;
		content.insert(content.length(), "\n");
	}
	return (content);
}
