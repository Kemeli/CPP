#include "AForm.hpp"

AForm::AForm() : _name("default AForm"), _signed(false), _gradeToSign(50), _gradeToExecute(50) {}

AForm::~AForm() {}

AForm::AForm(
	const std::string& name, int gradeToSign,int gradeToExecute) :
	_name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	checkGradeRange(_gradeToSign);
	checkGradeRange(_gradeToExecute);
}

void AForm::checkGradeRange(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& obj) :
	_name(obj._name),
	_signed(obj._signed),
	_gradeToSign(obj._gradeToSign),
	_gradeToExecute(obj._gradeToExecute)
{
}

AForm& AForm::operator= (const AForm& obj) {
	if (this == &obj)
		return *this;
	_signed = obj._signed;
	const_cast<std::string&>(_name) = obj._name;
	const_cast<int&>(_gradeToSign) = obj._gradeToSign;
	const_cast<int&>(_gradeToExecute) = obj._gradeToExecute;

	return *this;
}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

const std::string& AForm::getTarget() const {
	return _target;
}

void AForm::setName(std::string name)
{
	const_cast<std::string&>(this->_name) = name;
}

void AForm::setSigned(bool signature)
{
	this->_signed = signature;
}

void AForm::setGradeToSign(int gradeToSign)
{
	const_cast<int&>(this->_gradeToSign) = gradeToSign;
}

void AForm::setGradeToExecute(int gradeToExecute)
{
	const_cast<int&>(this->_gradeToExecute) = gradeToExecute;
}

void AForm::setTarget(std::string target)
{
	const_cast<std::string&>(this->_target) = target;
}

void AForm::beSigned(const Bureaucrat& name) {
	if (name.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

const char* AForm::NotSignedException::what() const throw() {
	return "Form is not signed";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form name: " << form.getName() << "\n" \
		<< "Signed: " << std::boolalpha << form.getSigned() << "\n" \
		<< "Grade required to sign: " << form.getGradeToSign() << "\n" \
		<< "Grade required to execute: " << form.getGradeToExecute() << "\n" \
		<< "Target: " << form.getTarget() << "\n";

	return os;
}

void AForm::checkExecutionRequirements(Bureaucrat const& executor) const {
	if (!getSigned()) {
		throw NotSignedException();
	}

	if (executor.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
}
