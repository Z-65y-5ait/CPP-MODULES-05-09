#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 140);
        Bureaucrat alice("Alice", 50);
        Bureaucrat charlie("Charlie", 1);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("robot");
        PresidentialPardonForm pardon("Marvin");

        bob.signForm(shrubbery);
        alice.signForm(shrubbery);
        alice.executeForm(shrubbery);

        charlie.signForm(robotomy);
        alice.executeForm(robotomy);

        charlie.signForm(pardon);
        charlie.executeForm(pardon);
        {
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
            if (rrf)
            {
                std::cout << *rrf << std::endl;
                delete rrf;
            }
        }
    }
    catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
