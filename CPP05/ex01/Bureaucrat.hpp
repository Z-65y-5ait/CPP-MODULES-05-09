#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& b);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat& operator=(const Bureaucrat& b);
		int getGrade() const;
		std::string const getName() const;
		void IncrementGrade();
		void DecrementGrade();
		void signForm(Form& f);
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
};
  
std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);

#endif