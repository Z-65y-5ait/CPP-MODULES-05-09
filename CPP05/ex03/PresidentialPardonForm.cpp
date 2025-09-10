#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), target("default")
{
	std::cout << "Default Constructor Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &f)
	: AForm(f), target(f.target)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: AForm("PresidentialPardonForm", 25, 5), target(target)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &f)
{
	if (this != &f)
	{
		AForm::operator=(f);
		this->target = target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
    	throw (FormNotSignedException());
	if (executor.getGrade() > this->getGradeE())
    	throw (GradeTooLowException());
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const char* PresidentialPardonForm::FormNotSignedException::what() const throw()
{
	return ("Not signed!");
}
