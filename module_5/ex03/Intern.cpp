#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& obj) {
	*this = obj;
}

Intern& Intern::operator= (const Intern& obj) {
	if (this == &obj)
		return *this;
	return *this;
}

const char * Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}

AForm *Intern::makeRobotomyForm(const std::string target)
{
	return new RobotomyRequestForm(target);
}


AForm *Intern::makePresidentialForm(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeShrubberyForm(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
	if (form_name.compare("PresidentialPardonForm")
		&& form_name.compare("RobotomyRequestForm")
		&& form_name.compare("ShrubberyCreationForm"))
	{
		throw Intern::FormNotFoundException();
	}

	AForm *(Intern::*forms[4])(std::string) = {
		&Intern::makePresidentialForm,
		NULL,
		&Intern::makeRobotomyForm,
		&Intern::makeShrubberyForm,
	};

	AForm *createdForm = (this->*forms[form_name[0] % 4])(target);
	std::cout << "Intern creates " << createdForm->getName() << std::endl;

	return createdForm;
}
