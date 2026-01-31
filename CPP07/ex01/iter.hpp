#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void printElement(T& e)
{
    std::cout << e << std::endl;
}

template <typename T>
void iter(T* ptr, size_t size, void (*FuncPtr)(T&))
{
	size_t i = 0;
	while (i < size)
	{
		FuncPtr(ptr[i]);
		i++;
	}
}

#endif