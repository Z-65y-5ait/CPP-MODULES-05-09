#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& b);
		Intern& operator=(const Intern& b);
		AForm* makeForm(std::string nameF, std::string nameT);
};

#endif