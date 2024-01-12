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

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	if (name == "robotomy request")
		return new RobotomyRequestForm(target);
	else if (name == "presidential pardon")
		return new PresidentialPardonForm(target);
	else if (name == "shrubbery creation")
		return new ShrubberyCreationForm(target);
	else
		throw Intern::FormNotFoundException();
}
