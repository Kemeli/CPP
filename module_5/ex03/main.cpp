#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	AForm* ppf;
	AForm* scf;
	AForm* nvf;

	Bureaucrat b1("Deep Thougth", 25);
	std::cout << "\nBureaucrat created: " << b1;
	Bureaucrat b2("Ford", 5);
	std::cout << "Bureaucrat created: " << b2;

	std::cout << ANSI_COLOR_BLUE << "\n------Intern creates RobotomyRequestForm------\n\n" << RESET_COLOR;
	try
	{
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		std::cout << *rrf << std::endl;

		std::cout << "Deep Thought signed form: ";
		b1.signForm(*rrf);
		std::cout << GREEN << "\nForm created:\n" << RESET_COLOR << *rrf;

		std::cout << GREEN << "\nExecuting form...\n" << RESET_COLOR;
		b2.executeForm(*rrf);
		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << ANSI_COLOR_BLUE << "\n------Intern creates PresidentialPardonForm------\n\n" << RESET_COLOR;
	try
	{
		ppf = someRandomIntern.makeForm("PresidentialPardonForm", "home");
		std::cout << *ppf << std::endl;

		std::cout << "Deep Thought signed form: ";
		std::cout << "\n\nHEEEEEEEEEEEEEEEERE\n\n";
		b1.signForm(*ppf);
		std::cout << GREEN << "\nForm created:\n" << RESET_COLOR << *ppf;

		std::cout << GREEN << "\nExecuting form...\n" << RESET_COLOR;
		b2.executeForm(*ppf);
		delete ppf;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << ANSI_COLOR_BLUE << "\n------Intern creates ShrubberyCreationForm------\n\n" << RESET_COLOR;
	try
	{
		scf = someRandomIntern.makeForm("ShrubberyCreationForm", "street");
		std::cout << *scf << std::endl;

		std::cout << "Deep Thought signed form: ";
		b1.signForm(*scf);
		std::cout << GREEN << "\nForm created:\n" << RESET_COLOR << *scf;

		std::cout << GREEN << "\nExecuting form...\n" << RESET_COLOR;
		b2.executeForm(*scf);
		delete scf;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << ANSI_COLOR_BLUE << "\n------Intern creates invalid form------\n\n" << RESET_COLOR;
	try
	{
		nvf = someRandomIntern.makeForm("invalud form name", "Bender");
		std::cout << *nvf << std::endl;

		std::cout << "Deep Thought signed form: ";
		b1.signForm(*nvf);
		std::cout << GREEN << "\nForm created:\n" << RESET_COLOR << *nvf;

		std::cout << GREEN << "\nExecuting form...\n" << RESET_COLOR;
		b2.executeForm(*nvf);
		delete nvf;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
