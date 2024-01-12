#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	// ShrubberyCreationForm tests
	try {
		ShrubberyCreationForm form1("f1");
		ShrubberyCreationForm form2(form1); // Copy constructor
		ShrubberyCreationForm form3("f3");
		form3 = form1; // Assignment operator

		// Modify the copied and assigned forms
		form2.setTarget("f2");
		form3.setTarget("f3");

		// Print the forms
		std::cout << "Copied ShrubberyCreationForm: " << form2 << std::endl;
		std::cout << "Assigned ShrubberyCreationForm: " << form3 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what();
	}

	// RobotomyRequestForm tests
	try {
		RobotomyRequestForm form1("f1");
		RobotomyRequestForm form2(form1); // Copy constructor
		RobotomyRequestForm form3("f3");
		form3 = form1; // Assignment operator

		// Modify the copied and assigned forms
		form2.setTarget("f2");
		form3.setTarget("f3");

		// Print the forms
		std::cout << "Copied RobotomyRequestForm: " << form2 << std::endl;
		std::cout << "Assigned RobotomyRequestForm: " << form3 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what();
	}

	// PresidentialPardonForm tests
	try {
		PresidentialPardonForm form1("f1");
		PresidentialPardonForm form2(form1); // Copy constructor
		PresidentialPardonForm form3("f3");
		form3 = form1; // Assignment operator

		// Modify the copied and assigned forms
		form2.setTarget("f2");
		form3.setTarget("f3");

		// Print the forms
		std::cout << "Copied PresidentialPardonForm: " << form2 << std::endl;
		std::cout << "Assigned PresidentialPardonForm: " << form3 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what();
	}
}
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	// ShrubberyCreationForm copy constructor test
	try {
		ShrubberyCreationForm form1("f1");
		ShrubberyCreationForm form2(form1); // Copy constructor

		// Modify the copied form
		form2.setTarget("f2");

		// Print the forms
		std::cout << "Original ShrubberyCreationForm: " << form1 << std::endl;
		std::cout << "Copied ShrubberyCreationForm: " << form2 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what();
	}

	// ShrubberyCreationForm assignment operator test
	try {
		ShrubberyCreationForm form1("f1");
		ShrubberyCreationForm form3("f3");
		form3 = form1; // Assignment operator

		// Modify the assigned form
		form3.setTarget("f3");

		// Print the forms
		std::cout << "Original ShrubberyCreationForm: " << form1 << std::endl;
		std::cout << "Assigned ShrubberyCreationForm: " << form3 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what();
	}

	// RobotomyRequestForm copy constructor test
	try {
		RobotomyRequestForm form1("f1");
		RobotomyRequestForm form2(form1); // Copy constructor

		// Modify the copied form
		form2.setTarget("f2");

		// Print the forms
		std::cout << "Original RobotomyRequestForm: " << form1 << std::endl;
		std::cout << "Copied RobotomyRequestForm: " << form2 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what();
	}

	// RobotomyRequestForm assignment operator test
	try {
		RobotomyRequestForm form1("f1");
		RobotomyRequestForm form3("f3");
		form3 = form1; // Assignment operator

		// Modify the assigned form
		form3.setTarget("f3");

		// Print the forms
		std::cout << "Original RobotomyRequestForm: " << form1 << std::endl;
		std::cout << "Assigned RobotomyRequestForm: " << form3 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what();
	}

	// PresidentialPardonForm copy constructor test
	try {
		PresidentialPardonForm form1("f1");
		PresidentialPardonForm form2(form1); // Copy constructor

		// Modify the copied form
		form2.setTarget("f2");

		// Print the forms
		std::cout << "Original PresidentialPardonForm: " << form1 << std::endl;
		std::cout << "Copied PresidentialPardonForm: " << form2 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what();
	}

	// PresidentialPardonForm assignment operator test
	try {
		PresidentialPardonForm form1("f1");
		PresidentialPardonForm form3("f3");
		form3 = form1; // Assignment operator

		// Modify the assigned form
		form3.setTarget("f3");

		// Print the forms
		std::cout << "Original PresidentialPardonForm: " << form1 << std::endl;
		std::cout << "Assigned PresidentialPardonForm: " << form3 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what();
	}
}
