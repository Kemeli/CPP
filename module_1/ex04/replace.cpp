#include "FileManipulation.hpp"
#include <fstream>

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
