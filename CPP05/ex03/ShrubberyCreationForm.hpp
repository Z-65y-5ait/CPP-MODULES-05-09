#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
    	std::string target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(const ShrubberyCreationForm &f);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &f);
		virtual void execute(Bureaucrat const & executor) const;
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
};

#endif