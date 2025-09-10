#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationFormDefault", 145, 137), target("default")
{
	std::cout << "Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &f)
	: AForm(f), target(f.target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &f)
{
	if (this != &f)
	{
		AForm::operator=(f);
		this->target = target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
    	throw (FormNotSignedException());
	if (executor.getGrade() > this->getGradeE())
    	throw (GradeTooLowException());
	std::ofstream file((this->target + "_shrubbery").c_str());
	if (!file)
    	throw (std::ofstream::failure("Failed to open file"));
	file << "   /\\\n";
	file << "  /  \\\n";
	file << " /++++\\\n";
	file << "   ||\n";
}

const char* ShrubberyCreationForm::FormNotSignedException::what() const throw()
{
	return ("Not signed!");
}
