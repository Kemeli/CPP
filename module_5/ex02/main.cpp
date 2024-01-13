#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat b1("Deep Thought", 1);
	std::cout << "\nBureaucrat created: " << b1 << std::endl;

	std::cout << PINK << "   SHRUBBERY CREATION FORM TEST   " << RESET_COLOR;
	std::cout << ANSI_COLOR_BLUE "\x1b[34m" << "\n\n------bureaucrat can execute the form------\n" << RESET_COLOR;
	try {
		Bureaucrat b2("Slartibartfast", 90);
		std::cout << "Bureaucrat created: " << b2 << std::endl;

		ShrubberyCreationForm form("f1");
		std::cout << "Deep Thought signed form: ";
		b1.signForm(form);
		std::cout << GREEN << "\nForm created:\n" << RESET_COLOR << form;

		std::cout << GREEN << "\nExecuting form...\n" << RESET_COLOR;
		b2.executeForm(form);

	} catch (std::exception& e) {
		std::cout << e.what();
	}

	std::cout << ANSI_COLOR_BLUE "\x1b[34m" << "\n------bureaucrat can NOT execute the form (Grade Too Low)------\n" << RESET_COLOR;
	try {
		Bureaucrat	bureaucrat("Benjy", 148);
		std::cout << "Bureaucrat created: " << bureaucrat << std::endl;

		ShrubberyCreationForm form("f2");
		std::cout << "Deep Thought signed form: ";
		b1.signForm(form);
		std::cout << GREEN << "\nForm created:\n" << RESET_COLOR << form;

		std::cout << GREEN << "\nExecuting form...\n" << RESET_COLOR;
		bureaucrat.executeForm(form);

	} catch (std::exception& e) {
		std::cout << e.what();
	}

	std::cout << ANSI_COLOR_BLUE "\x1b[34m"  << "\n" << PINK << "   ROBOTOMY REQUEST FORM TEST   " << RESET_COLOR;
	std::cout << "\n\n------bureaucrat can execute the form------\n" << RESET_COLOR;
	try {
		Bureaucrat b3("Lunkwill", 40);
		std::cout << "Bureaucrat created: " << b3 << std::endl;

		RobotomyRequestForm	form("f3");
		std::cout << "Deep Thought signed form: ";
		b1.signForm(form);
		std::cout << GREEN << "\nForm created:\n" << RESET_COLOR << form;

		std::cout << GREEN << "\nExecuting form...\n" << RESET_COLOR;
		b3.executeForm(form);

	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << ANSI_COLOR_BLUE "\x1b[34m" << "\n------bureaucrat can NOT execute the form (Grade Too Low)------\n" << RESET_COLOR;
	try {
		Bureaucrat	b4("Arthur", 148);
		std::cout << "Bureaucrat created: " << b4 << std::endl;

		RobotomyRequestForm	form("f4");
		std::cout << "Deep Thought signed form: ";
		b1.signForm(form);
		std::cout << GREEN << "\nForm created:\n" << RESET_COLOR << form;

		std::cout << GREEN << "\nExecuting form...\n" << RESET_COLOR;
		b4.executeForm(form);

	} catch (std::exception& e) {
		std::cout << e.what();
	}

	std::cout << ANSI_COLOR_BLUE "\x1b[34m" << "\n------bureaucrat can NOT execute the form (Form Not Signed)------\n" << RESET_COLOR;
	try {
		Bureaucrat	b5("Ford", 20);
		std::cout << "Bureaucrat created: " << b5 << std::endl;

		RobotomyRequestForm	form("f5");
		std::cout << "Deep Thought did not sign form!\n";

		std::cout << GREEN << "\nForm created:\n" << RESET_COLOR << form;

		std::cout << GREEN << "\nExecuting form...\n" << RESET_COLOR;
		b5.executeForm(form);

	} catch (std::exception& e) {
		std::cout << e.what();
	}

	std::cout << PINK << "\n" << "   PRESIDENTIAL PARDON FORM TEST   " << RESET_COLOR;
	std::cout << ANSI_COLOR_BLUE "\x1b[34m" << "\n\n------bureaucrat can execute the form------\n" << RESET_COLOR;
	try {
		Bureaucrat	b6("Marvim", 5);
		std::cout << "Bureaucrat created: " << b6 << std::endl;

		PresidentialPardonForm	form("f6");
		std::cout << "Deep Thought signed form: ";
		b1.signForm(form);
		std::cout << GREEN << "\nForm created:\n" << RESET_COLOR << form;

		std::cout << GREEN << "\nExecuting form...\n" << RESET_COLOR;
		b6.executeForm(form);

	} catch (std::exception& e) {
		std::cout << e.what();
	}

	std::cout << ANSI_COLOR_BLUE "\x1b[34m" << "\n------bureaucrat can NOT execute the form (Grade Too Low)------\n" << RESET_COLOR;
	try {
		Bureaucrat	b7("Tricia", 6);
		std::cout << "Bureaucrat created: " << b7 << std::endl;

		PresidentialPardonForm	form("f7");
		std::cout << "Deep Thought signed form: ";
		b1.signForm(form);
		std::cout << GREEN << "\nForm created:\n" << RESET_COLOR << form;

		std::cout << GREEN << "\nExecuting form...\n" << RESET_COLOR;
		b7.executeForm(form);

	} catch (std::exception& e) {
		std::cout << e.what();
	}

	std::cout << ANSI_COLOR_BLUE "\x1b[34m" << "\n------bureaucrat can NOT execute the form (Form Not Signed)------\n" << RESET_COLOR;
	try {
		Bureaucrat	b8("Clarice", 2);
		std::cout << "Bureaucrat created: " << b8 << std::endl;

		PresidentialPardonForm	form("f8");
		std::cout << "Deep Thought did not sign form!\n";

		std::cout << GREEN << "\nForm created:\n" << RESET_COLOR << form;

		std::cout << GREEN << "\nExecuting form...\n" << RESET_COLOR;
		b8.executeForm(form);

	} catch (std::exception& e) {
		std::cout << e.what();
	}
}
	//##########################################################################
	// OPTIONAL TESTS
	//##########################################################################

// 	std::cout << PINK << "\n" << "   OTHER TESTS   \n" << RESET_COLOR;
// 	std::cout << ANSI_COLOR_BLUE "\x1b[34m" << "\n------ShrubberyCreationForm copy constructor------\n" << RESET_COLOR;
// 	try {
// 		ShrubberyCreationForm form1("f1");
// 		ShrubberyCreationForm form2(form1); // Copy constructor

// 		// Modify the copied form
// 		form2.setTarget("f2");

// 		// Print the forms
// 		std::cout << "Original ShrubberyCreationForm:\n" << form1 << std::endl;
// 		std::cout << "Copied ShrubberyCreationForm:\n" << form2 << std::endl;
// 	} catch (std::exception& e) {
// 		std::cout << e.what();
// 	}

// 	std::cout << ANSI_COLOR_BLUE "\x1b[34m" << "\n------ShrubberyCreationForm assignment operator------\n" << RESET_COLOR;

// 	try {
// 		ShrubberyCreationForm form1("f1");
// 		ShrubberyCreationForm form3("f3");
// 		form3 = form1; // Assignment operator

// 		// Modify the assigned form
// 		form3.setTarget("f3");

// 		// Print the forms
// 		std::cout << "Original ShrubberyCreationForm:\n" << form1 << std::endl;
// 		std::cout << "Assigned ShrubberyCreationForm:\n" << form3 << std::endl;
// 	} catch (std::exception& e) {
// 		std::cout << e.what();
// 	}

// 	std::cout << ANSI_COLOR_BLUE "\x1b[34m" << "\n------RobotomyRequestForm copy constructor------\n" << RESET_COLOR;
// 	try {
// 		RobotomyRequestForm form1("f1");
// 		RobotomyRequestForm form2(form1); // Copy constructor

// 		// Modify the copied form
// 		form2.setTarget("f2");

// 		// Print the forms
// 		std::cout << "Original RobotomyRequestForm:\n" << form1 << std::endl;
// 		std::cout << "Copied RobotomyRequestForm:\n" << form2 << std::endl;
// 	} catch (std::exception& e) {
// 		std::cout << e.what();
// 	}

// 	std::cout << ANSI_COLOR_BLUE "\x1b[34m" << "\n------RobotomyRequestForm assignment operator------\n" << RESET_COLOR;
// 	try {
// 		RobotomyRequestForm form1("f1");
// 		RobotomyRequestForm form3("f3");
// 		form3 = form1; // Assignment operator

// 		// Modify the assigned form
// 		form3.setTarget("f3");

// 		// Print the forms
// 		std::cout << "Original RobotomyRequestForm:\n" << form1 << std::endl;
// 		std::cout << "Assigned RobotomyRequestForm:\n" << form3 << std::endl;
// 	} catch (std::exception& e) {
// 		std::cout << e.what();
// 	}

// 	std::cout << ANSI_COLOR_BLUE "\x1b[34m" << "\n------PresidentialPardonForm copy constructor------\n" << RESET_COLOR;
// 	try {
// 		PresidentialPardonForm form1("f1");
// 		PresidentialPardonForm form2(form1); // Copy constructor

// 		// Modify the copied form
// 		form2.setTarget("f2");

// 		// Print the forms
// 		std::cout << "Original PresidentialPardonForm:\n" << form1 << std::endl;
// 		std::cout << "Copied PresidentialPardonForm:\n" << form2 << std::endl;
// 	} catch (std::exception& e) {
// 		std::cout << e.what();
// 	}

// 	std::cout << ANSI_COLOR_BLUE "\x1b[34m" << "\n------PresidentialPardonForm assignment operator------\n" << RESET_COLOR;
// 	try {
// 		PresidentialPardonForm form1("f1");
// 		PresidentialPardonForm form3("f3");
// 		form3 = form1; // Assignment operator

// 		// Modify the assigned form
// 		form3.setTarget("f3");

// 		// Print the forms
// 		std::cout << "Original PresidentialPardonForm:\n" << form1 << std::endl;
// 		std::cout << "Assigned PresidentialPardonForm:\n" << form3 << std::endl;
// 	} catch (std::exception& e) {
// 		std::cout << e.what();
// 	}
// }

