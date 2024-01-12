#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default RobotomyRequestForm", 72, 45)
{
	this->setTarget("street");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("RobotomyRequestForm", 72, 45)
{
	this->setTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) :
	AForm(obj)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	AForm::operator=(obj);
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::checkExecutionRequirements(executor);
	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " robotomization failed" << std::endl;
}
