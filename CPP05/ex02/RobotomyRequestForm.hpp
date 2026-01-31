#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
    	std::string target;
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(const RobotomyRequestForm &f);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &f);
		virtual void execute(Bureaucrat const & executor) const;
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
};

#endif