#include "Form.hpp"

Form::Form() : _name("default Form"), _signed(false), _gradeToSign(50), _gradeToExecute(50) {}

Form::~Form() {}

Form::Form(const Form& obj) :
	_name(obj._name),
	_signed(obj._signed),
	_gradeToSign(obj._gradeToSign),
	_gradeToExecute(obj._gradeToExecute)
{
}

Form& Form::operator= (const Form& obj) {
	if (this == &obj)
		return *this;
	_signed = obj._signed;
	const_cast<std::string&>(_name) = obj._name;
	const_cast<int&>(_gradeToSign) = obj._gradeToSign;
	const_cast<int&>(_gradeToExecute) = obj._gradeToExecute;

	return *this;
}

void Form::checkGradeRange(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Form::Form(
	const std::string& name, int gradeToSign,int gradeToExecute) :
	_name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	checkGradeRange(_gradeToSign);
	checkGradeRange(_gradeToExecute);
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& name) {
	if (name.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form name: " << form.getName() << "\n" \
		<< "Signed: " << std::boolalpha << form.getSigned() << "\n" \
		<< "Grade required to sign: " << form.getGradeToSign() << "\n" \
		<< "Grade required to execute: " << form.getGradeToExecute() << "\n";
	return os;
}
