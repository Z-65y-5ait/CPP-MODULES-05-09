#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->arr = 0;
	this->size = 0;
}

template <typename T>
Array<T>::~Array()
{
	if (this->arr)
		delete[] this->arr;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->arr = new T[n]();
	this->size = n;
}

template <typename T>
Array<T>::Array(const Array<T>& a)
{
	this->arr = new T[a.size];
	this->size = a.size;
	size_t i = 0;
	while (i < this->size)
	{
		this->arr[i] = a.arr[i];
		i++;
	}
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>& a)
{
	if (this != &a)
	{
		if (arr)
			delete[] arr;
		this->size = a.size;
		this->arr = new T[size];
		size_t i = 0;
		while (i < this->size)
		{
			this->arr[i] = a.arr[i];
			i++;
		}
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= this->size)
		throw (std::out_of_range("invalid index !"));
	else
		return (this->arr[index]);
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index > this->size || index < 0)
		throw (std::out_of_range("invalid index !"));
	else
		return (this->arr[index]);
}

template <typename T>
size_t Array<T>::getSize() const
{
	return (size);
}
