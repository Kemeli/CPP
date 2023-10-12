#ifndef FILE_MANIPULATION
# define FILE_MANIPULATION

#include <iostream>

class FileManipulation
{
	private:
	char		*inFile;
	std::string	be_replaced;
	std::string	replace;

	public:
	char		*get_infile();
	std::string	get_be_replaced();
	std::string	get_replace();

	void		set_infile(char *inFile);
	void		set_be_replaced(std::string replaced);
	void		set_replace(std::string replace);
};

#endif
