#pragma once

#include <iostream>

template <typename T>

class Array {
	private:
		T*				_array;
		unsigned int	_length;
	public:
		Array() : _array(NULL), _length(0){};

		Array(unsigned int n) {
			_array = new T[n];
			_length = n;
		};
		Array(const Array& other) {
			_array = new T[other._length];
			_length = other._length;
			for (unsigned int i = 0; i < other._length; i++) {
				_array[i] = other._array[i];
			}
		};

		Array& operator=(const Array& other) {
			if (this != &other) {
				this->_array = other._array;
				delete[] _array;
			}
			this->_length = other._length;
			for (unsigned int i = 0; i < other._length; i++) {
				_array[i] = other._array[i];
			}
		};

		~Array() {
			delete[] _array;
		};

		T&	operator[](unsigned int i) {
			if (i >= _length)
				throw std::out_of_range("ALOOOOOOOOOOOOOOOOOOOOOOO!!!!!!!!!");
			return _array[i];
		};

		unsigned int	size() {
			return _length;
		}
};