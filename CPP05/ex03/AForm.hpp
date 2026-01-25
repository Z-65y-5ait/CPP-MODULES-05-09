#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const name;
		bool signedval;
		const int grade_e;
		const int grade_s;
	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm &f);
		AForm(std::string const name, const int grade_s, const int grade_e);
		AForm& operator=(const AForm &f);
		int getGradeS() const;
		int getGradeE() const;
		bool getSign() const;
		std::string const getName() const;
		void beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const & e) const = 0;
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
  
std::ostream& operator<<(std::ostream &os, const AForm &b);

#endif