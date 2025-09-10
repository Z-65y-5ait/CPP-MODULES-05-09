#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
	: name("default"), grade(150)
{
	std::cout << "Default Constructor Called" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Called" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat& b)
	: name(b.name), grade(b.grade)
{
	
}
Bureaucrat::Bureaucrat(std::string const name, int grade)
	: name(name), grade(grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("too low!");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
	(void)b;
	return (*this);
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

std::string const Bureaucrat::getName() const
{
	return (name);
}

void Bureaucrat::IncrementGrade()
{
	this->grade--;
	if (this->grade < 1)
		throw (GradeTooHighException());
}

void Bureaucrat::DecrementGrade()
{
	this->grade++;
	if (grade > 150)
		throw (GradeTooLowException());
}

void Bureaucrat::signForm(Form& f)
{
	try {
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}