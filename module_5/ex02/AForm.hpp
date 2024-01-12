#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	AForm();
	virtual ~AForm();
	AForm(const AForm& obj);
	AForm& operator= (const AForm& obj);

	AForm(const std::string& name, int gradeToSign, int gradeToExecute);

	const std::string&	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	const std::string&	getTarget() const;

	void				setName(std::string name);
	void				setSigned(bool signature);
	void				setGradeToSign(int gradeToSign);
	void				setGradeToExecute(int gradeToExecute);
	void				setTarget(std::string target);

	void				beSigned(const Bureaucrat& name);
	void				checkGradeRange(int grade);

	virtual void		execute(Bureaucrat const & executor) const = 0;
	void 				checkExecutionRequirements(Bureaucrat const& executor) const;

private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	const std::string	_target;
};

std::ostream&			operator<<(std::ostream& os, const AForm& form);

#endif
