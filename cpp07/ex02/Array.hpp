#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class	Array {
	private:
		T* _elements;
		unsigned int _size;
	public:
		Array() : _elements(NULL), _size(0) {};

		Array(unsigned int size) : _size(size) {
			if (size > 0)
				_elements = new T[size]();
			else
				_elements = NULL;
		};

		Array(const Array& other) : _size(other._size) {
			if (_size > 0) {
				_elements = new T[_size]();
				for (unsigned int i = 0; i < _size; i++)
					_elements[i] = other._elements[i];
			}
			else
				_elements = NULL;
		};

		Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] _elements;

				_size = other._size;
				if (_size > 0) {
					_elements = new T[_size]();
					for (unsigned int i = 0; i < _size; i++)
						_elements[i] = other._elements[i];
				}
				else
					_elements = NULL;
			}
			return *this;
		};

		~Array() {
			delete[] _elements;
		};

		T& operator[](unsigned int i) {
			if (i >= _size) // no hace falta controlar si es negativo porque unsigned int siempre es positivo
				throw (std::exception());
			return _elements[i];
		};

		unsigned int size() const {
			return _size;
		};
};

#endif