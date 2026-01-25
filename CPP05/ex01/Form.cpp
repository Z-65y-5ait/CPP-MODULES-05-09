#include "Form.hpp"

Form::Form()
	: name("default"), signedval(0), grade_e(150), grade_s(150)
{
	std::cout << "Default Constructor Called" << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor Called" << std::endl;
}

Form::Form(const Form &f)
	: name(f.name), signedval(f.signedval), grade_e(f.grade_e), grade_s(f.grade_s)
{

}

Form& Form::operator=(const Form &f)
{
	(void)f;
	return (*this);
}

int Form::getGradeS() const
{
	return (grade_s);
}

int Form::getGradeE() const
{
	return (grade_e);
}

bool Form::getSign() const
{
	return (signedval);
}

std::string const Form::getName() const
{
	return (name);
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= grade_s)
		this->signedval = 1;
	else
		throw (GradeTooLowException());
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("it's too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("it's too low!");
}

Form::Form(std::string const name, const int grade_s, const int grade_e)
	: name(name), signedval(0), grade_e(grade_e), grade_s(grade_s)
{

}

std::ostream& operator<<(std::ostream &os, const Form &b)
{
	os << b.getName() << " " << b.getSign() << " " << b.getGradeS() << " " << b.getGradeE();
	return (os);
}