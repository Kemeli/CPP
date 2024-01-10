#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& a);
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& a);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor) const;
};
