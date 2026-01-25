#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <list>
#include <vector>
#include <deque>

template <typename T>
typename T::iterator easyfind(T& a, int b)
{
	for(typename T::iterator it = a.begin(); it != a.end(); it++)
	{
		if (*it == b)
			return (it);
	}
	return (a.end());
}

#endif