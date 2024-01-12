#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const ShrubberyCreationForm& a);
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& a);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(std::string target);

		void execute(const Bureaucrat& executor) const;

	private:
		ShrubberyCreationForm();

};

#endif
