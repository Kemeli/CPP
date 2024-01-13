#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << PINK << "\n---signing is successfull---\n" << RESET_COLOR;
	try {
		Bureaucrat	bureaucrat("Arthur", 50);
		std::cout << "___Bureaucrat created___\n" << bureaucrat << std::endl;

		Form form("f1", 50, 20);
		std::cout << "___Form created___\n" << form << std::endl;

		std::cout << "___Signing form___" << std::endl;
		bureaucrat.signForm(form);

		std::cout << "\n__Updated Form__\n" << form;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << PINK << "\n---signing is unsuccessful---\n" << RESET_COLOR;
	try {
		Bureaucrat	bureaucrat("Zaphod", 75);
		std::cout << "___Bureaucrat created___\n" << bureaucrat << std::endl;

		Form form("f2", 40, 1);
		std::cout << "___Form created___\n" << form << std::endl;

		std::cout << "___Signing form___" << std::endl;
		bureaucrat.signForm(form);

		std::cout << "\n__Updated Form__\n" << form;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << PINK << "\n---form can not be created (Grade Too High)---\n" << RESET_COLOR;
	try {
		Bureaucrat bureaucrat("Ford", 10);
		std::cout << "___Bureaucrat created___\n" << bureaucrat << std::endl;

		Form form("f3", 0, 1);
		std::cout << "___Form created___\n" << form << std::endl;

		std::cout << "___Signing form___" << std::endl;
		bureaucrat.signForm(form);

		std::cout << "\n__Updated Form__\n" << form;

	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << PINK << "\n---form can not be created (Grade Too Low)---\n" << RESET_COLOR;
	try {
		Bureaucrat	bureaucrat("Marvin", 10);
		std::cout << "___Bureaucrat created___\n" << bureaucrat << std::endl;

		Form form("f4", 152, 1);
		std::cout << "___Form created___\n" << form << std::endl;

		std::cout << "___Signing form___" << std::endl;
		bureaucrat.signForm(form);

		std::cout << "\n__Updated Form__\n" << form;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
