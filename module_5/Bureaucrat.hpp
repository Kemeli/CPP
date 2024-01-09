#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

# define PINK "\033[35m"
# define RESET_COLOR "\033[0m"

class Bureaucrat {
public:
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat& operator=(const Bureaucrat& obj);

	Bureaucrat(const std::string& name, int grade);

	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

private:
	const std::string name;
	int grade;

	void checkGradeRange(int newGrade);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
