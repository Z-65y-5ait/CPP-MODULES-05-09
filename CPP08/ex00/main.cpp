#include "easyfind.hpp"

int main()
{

	std::list<int> l;
	l.push_back(1);
	l.push_back(22);
	l.push_back(3);
	std::list<int>::iterator it1 = easyfind(l, 22);
	std::cout << *it1 << std::endl;

	return (0);
}