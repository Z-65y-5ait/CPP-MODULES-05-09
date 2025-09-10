#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T& min(T& c, T& d)
{
	if (c > d)
		return (d);
	else
		return (c);
}

template <typename T>
T& max(T& c, T& d)
{
	if (c > d)
		return (c);
	else
		return (d);
}

#endif