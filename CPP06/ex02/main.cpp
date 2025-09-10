#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime> 

Base * generate(void)
{
	int choice = rand() % 3;
	if (choice == 0)
		return (new A());
	else if (choice == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base* p)
{
	if (!p)
		return ;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "undefined type" << std::endl;
}

void identify(Base& p)
{
	try{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...)
	{

	}
	try{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...)
	{

	}
	try{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...)
	{

	}
	std::cout << "undefined type" << std::endl;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
	int i = 0;
    while (i < 6)
	{
        Base* p = generate();
        std::cout << "identify(Base*): ";
        identify(p);
        std::cout << "identify(Base&): ";
        identify(*p);
		i++;
        delete p;
    }
    return 0;
}