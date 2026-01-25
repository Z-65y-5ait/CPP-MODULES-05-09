#include "AForm.hpp"

AForm::AForm()
	: name("default"), signedval(0), grade_e(150), grade_s(150)
{
	std::cout << "Default Constructor Called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Destructor Called" << std::endl;
}

AForm::AForm(const AForm &f)
	: name(f.name), signedval(f.signedval), grade_e(f.grade_e), grade_s(f.grade_s)
{

}

AForm& AForm::operator=(const AForm &f)
{
	(void)f;
	return (*this);
}

int AForm::getGradeS() const
{
	return (grade_s);
}

int AForm::getGradeE() const
{
	return (grade_e);
}

bool AForm::getSign() const
{
	return (signedval);
}

std::string const AForm::getName() const
{
	return (name);
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= grade_s)
		this->signedval = 1;
	else
		throw (GradeTooLowException());
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("it's too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("it's too low!");
}

AForm::AForm(std::string const name, const int grade_s, const int grade_e)
	: name(name), signedval(0), grade_e(grade_e), grade_s(grade_s)
{

}

std::ostream& operator<<(std::ostream &os, const AForm &b)
{
	os << b.getName() << " " << b.getSign() << " " << b.getGradeS() << " " << b.getGradeE();
	return (os);
}
