#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack()
		{
			std::cout << "Default Constructor Called" << std::endl;
		}

		~MutantStack()
		{
			std::cout << "Destructor Called" << std::endl;
		}

		MutantStack<T>& operator=(const MutantStack<T>& m)
		{
			std::stack<T>::operator=(m);
			return (*this);
		}

		MutantStack(const MutantStack<T>& m) : std::stack<T>(m)
		{

		}

		iterator begin()
		{
			return (this->c.begin());
		}

		iterator end()
		{
			return (this->c.end());
		}
};

#endif