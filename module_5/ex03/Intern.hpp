#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern {
public:
	class FormNotFoundException : public std::exception {
		public:
			const char* what() const throw();
	};

	Intern();
	~Intern();
	Intern(const Intern& obj);
	Intern& operator= (const Intern& obj);

	AForm*	makeForm(const std::string& name, const std::string& target);
};

#endif
