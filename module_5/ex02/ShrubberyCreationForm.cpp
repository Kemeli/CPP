#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default ShrubberyCreationForm", 145, 137)
{
	this->setTarget("home");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) :
	AForm(obj)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	AForm::operator=(obj);
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::checkExecutionRequirements(executor);
	std::ofstream file;
	std::string filename = this->getTarget() + "_shrubbery";
	file.open(filename.c_str());
	file << "      /\\\n";
	file << "     /\\*\\\n";
	file << "    /\\O\\*\\\n";
	file << "   /*/\\/\\/\\\n";
	file << "  /\\O\\/\\*\\/\\\n";
	file << " /\\*\\/\\*\\/\\/\\\n";
	file << "/\\O\\/\\/*/\\/O/\\\n";
	file << "      ||\n";
	file << "      ||\n";
	file << "      ||\n";
	file << "    \\====/\n";
	file << "     \\__/  \n";
	file.close();
}
