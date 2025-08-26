#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class   Span {
	private:
		std::vector<int>	_container;
		unsigned int	_maxSize;
		unsigned int	_currentSize;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		
		void	addNumber(int number);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		unsigned int	size() const { return _currentSize;};
};

#endif
