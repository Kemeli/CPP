#include "Bureaucrat.hpp"

int main()
{
	std::cout << PINK << "------Default Bureaucrat:------" << std::endl << RESET_COLOR;
	Bureaucrat b;
	std::cout << b;

	Bureaucrat b1("Arthur", 1);
	std::cout << PINK << "------Decrement Grade:------" << std::endl << RESET_COLOR;
	std::cout << b1;
	try
	{
		b1.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b1;

	std::cout << PINK << "------Increment Grade:------" << std::endl << RESET_COLOR;
	std::cout << b1;
	try
	{
		b1.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b1;


	std::cout << PINK << "------unsuccessful increment:------" << std::endl << RESET_COLOR;
	std::cout << b1;
	try
	{
		b1.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b1;

	Bureaucrat b2("Ford", 150);
	std::cout << PINK << "------unsuccessful decrement:------" << std::endl << RESET_COLOR;
	std::cout << b2;
	try
	{
		b2.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b2;


	std::cout << PINK << "------Grade too low:------" << std::endl << RESET_COLOR;
	try
	{
		Bureaucrat b3("Zaphod", 151);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << PINK << "------Grade too high:------" << std::endl << RESET_COLOR;
	try
	{
		Bureaucrat b4("Marvin", 0);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
