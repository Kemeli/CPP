#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default Bureaucrat"), grade(50) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& newName, int newGrade) : name(newName) {
	checkGradeRange(newGrade);
	grade = newGrade;
}

void Bureaucrat::checkGradeRange(int newGrade) {
	if (newGrade < 1)
		throw GradeTooHighException();
	else if (newGrade > 150)
		throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& obj)
{
	const_cast<std::string&>(this->name) = obj.name;
	this->grade = obj.grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	*this = obj;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low";
}

const std::string& Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	checkGradeRange(grade - 1);
	grade--;
}

void Bureaucrat::decrementGrade() {
	checkGradeRange(grade + 1);
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << "'s grade is: " << bureaucrat.getGrade() << std::endl;;
	return os;
}
