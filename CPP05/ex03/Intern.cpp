#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Default Constructor Called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Destructor Called" << std::endl;
}

Intern::Intern(const Intern& b)
{
	(void)b;
}

Intern& Intern::operator=(const Intern& b)
{
	(void)b;
	return (*this);
}

static AForm* makePresidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}

static AForm* makeRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm* makeShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string nameF, std::string nameT)
{
	AForm* (*FunPtr[3])(std::string) = {makePresidential, makeRobotomy, makeShrubbery};
	std::string order[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int i = 0;
	while (i < 3)
	{
		if (nameF == order[i])
		{
			std::cout << "Intern creates " << order[i] << std::endl;
			return (FunPtr[i](nameT));
		} 
		i++;
	}
	std::cout << "Intern doesn't know this form -> " << nameF << std::endl;
	return (NULL);
}
