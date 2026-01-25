#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestFormDefault", 72, 45), target("default")
{
	std::cout << "Default Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &f)
	: AForm(f), target(f.target)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &f)
{
	if (this != &f)
	{
		AForm::operator=(f);
		this->target = target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
    	throw (FormNotSignedException());
	if (executor.getGrade() > this->getGradeE())
    	throw (GradeTooLowException());
	std::cout << "Drilling Noises..." << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
}

const char* RobotomyRequestForm::FormNotSignedException::what() const throw()
{
	return ("Not signed!");
}
