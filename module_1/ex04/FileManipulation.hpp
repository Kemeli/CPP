#ifndef FILE_MANIPULATION
# define FILE_MANIPULATION

#include <iostream>

class FileManipulation
{
	private:
	std::string	inFile;
	std::string	be_replaced;
	std::string	replace;

	public:
	std::string	get_infile();
	std::string	get_be_replaced();
	std::string	get_replace();

	void		set_infile(char *inFile);
	void		set_be_replaced(std::string replaced);
	void		set_replace(std::string replace);
};


void	setters(FileManipulation& obj, char **argv);
char	open_files(std::ifstream& inFile,
					std::ofstream& outFile,
					FileManipulation& obj);
std::string	replace(FileManipulation& obj, std::ifstream& inFile);

#endif
