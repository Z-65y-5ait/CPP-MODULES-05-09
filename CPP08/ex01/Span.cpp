#include "Span.hpp"

Span::Span()
{
	N = 0;
	std::cout << "Default Constructor Called" << std::endl;
}

Span::~Span()
{
	std::cout << "Destructor Called" << std::endl;
}

Span::Span(unsigned int N)
{
	this->N = N;
	std::cout << "Constructor Called" << std::endl;
}

Span& Span::operator=(const Span& s)
{
	this->N = s.N;
	return (*this);
}

Span::Span(const Span& s)
	: N(s.N)
{

}

void Span::addNumber(int number)
{
	if (vect.size() >= N)
		throw (std::out_of_range("Full !"));
	vect.push_back(number);
}

int Span::shortestSpan()
{
	if (vect.size() < 2)
		throw (std::out_of_range("Few numbers !"));
	std::vector<int> vector = vect;
	std::sort(vector.begin(), vector.end());
	int f_diff = INT_MAX;
	size_t size_vect = vector.size() - 1;
	for (size_t i = 0; i < size_vect; i++)
	{
		int min_diff = vector[i + 1] - vector[i];
		if (f_diff > min_diff)
			f_diff = min_diff;
	}
	return (f_diff);
}

int Span::longestSpan()
{
	if (vect.size() < 2)
		throw (std::out_of_range("Few numbers !"));
	std::vector<int> vector = vect;
	std::sort(vector.begin(), vector.end());
	int f_diff = INT_MIN;
	size_t size_vect = vector.size() - 1;
	for (size_t i = 0; i < size_vect; i++)
	{
		int max_diff = vector[i + 1] - vector[i];
		if (f_diff < max_diff)
			f_diff = max_diff;
	}
	return (f_diff);
}

void Span::range_numbers(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	for (std::vector<int>::iterator it = first; it != last; ++it)
	{
		addNumber(*it);
	}
}