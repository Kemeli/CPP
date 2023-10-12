#include "FileManipulation.hpp"

FileManipulation::FileManipulation(){}

char	*FileManipulation::get_infile(){
	return (this->inFile);
}

std::string	FileManipulation::get_be_replaced(){
	return (this->be_replaced);
}

std::string	FileManipulation::get_replace(){
	return (this->replace);
}

void		FileManipulation::set_infile(char *inFile){
	this->inFile = inFile;
}

void		FileManipulation::set_be_replaced(std::string replaced){
	this->be_replaced = replaced;
}

void		FileManipulation::set_replace(std::string replace){
	this->replace = replace;
}
