#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default PresidentialPardonForm", 25, 5)
{
	this->setTarget("park");
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) :
	AForm(obj)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	AForm::operator=(obj);
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	AForm("PresidentialPardonForm", 25, 5)
{
	this->setTarget(target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::checkExecutionRequirements(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
