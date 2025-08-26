#include "Span.hpp"

Span::Span() : _maxSize(0), _currentSize(0) {}

Span::Span(unsigned int N): _maxSize(N), _currentSize(0) {}

Span::Span(const Span& other) : _container(other._container), _maxSize(other._maxSize), _currentSize(other._currentSize) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_currentSize = other._currentSize;
		_container = other._container;
	}
	return *this;
}

Span::~Span() {}

unsigned int    Span::shortestSpan() {
	if (_currentSize < 2)
		throw (std::runtime_error("Need at least 2 numbers"));

	std::vector<int> sorted = _container;
	std::sort(sorted.begin(), sorted.end());

	int shortest = sorted[1] - sorted[0];

	for (unsigned int i = 1; i < _currentSize - 1; i++) {
		if (sorted[i + 1] - sorted[i] < shortest)
			shortest = sorted[i + 1] - sorted[i];
	}
	return static_cast<unsigned int>(shortest);
}

unsigned int	Span::longestSpan() {
	if (_currentSize < 2)
		throw (std::runtime_error("Need at least 2 numbers"));
	
	std::vector<int>::iterator min = std::min_element(_container.begin(), _container.end());
	std::vector<int>::iterator max = std::max_element(_container.begin(), _container.end());

	
	return static_cast<unsigned int>(*max - *min);
}

void	Span::addNumber(int number) {
	if (_currentSize == _maxSize)
		throw (std::runtime_error("Span is full"));
	
	_container.push_back(number);
	_currentSize++;
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	std::iterator_traits<std::vector<int>::iterator>::difference_type distance = std::distance(begin, end);

	if (_currentSize + distance > _maxSize)
		throw (std::runtime_error("Span is full"));
	
	std::copy(begin, end, std::back_inserter(_container));
	_currentSize += distance;
}
