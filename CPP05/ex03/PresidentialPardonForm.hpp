#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
    	std::string target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(const PresidentialPardonForm &f);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &f);
		virtual void execute(Bureaucrat const & executor) const;
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
};

#endif