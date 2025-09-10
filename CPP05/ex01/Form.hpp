#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const name;
		bool signedval;
		const int grade_e;
		const int grade_s;
	public:
		Form();
		~Form();
		Form(const Form &f);
		Form(std::string const name, const int grade_s, const int grade_e);
		Form& operator=(const Form &f);
		int getGradeS() const;
		int getGradeE() const;
		bool getSign() const;
		std::string const getName() const;
		void beSigned(const Bureaucrat& b);
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
  
std::ostream& operator<<(std::ostream &os, const Form &b);

#endif