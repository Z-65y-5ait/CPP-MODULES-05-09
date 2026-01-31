#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

class Span
{
	private:
		unsigned int N;
		std::vector<int> vect;
	public:
		Span();
		Span(unsigned int N);
		Span& operator=(const Span& s);
		Span(const Span& s);
		~Span();
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void range_numbers(std::vector<int>::iterator first,
			std::vector<int>::iterator last);
};

#endif