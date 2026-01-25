#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T* arr;
		size_t size;
	public:
		Array();
		Array(unsigned int n);
		~Array();
		T& operator[](size_t index);
		const T& operator[](size_t index) const;
		Array<T>& operator=(Array<T>& a);
		Array(const Array<T>& a);
		size_t getSize() const;
};

#include "Array.tpp"

#endif