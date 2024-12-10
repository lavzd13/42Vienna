#include <iostream>

template <typename T>

void	iter(T* array, int length, void (*f)(T& a)) {
	if (length <= 0) {
		std::cout << "Can't work with empty array." << std::endl;
		return;
	}
	for (int i = 0; i < length; i++) {
		f(array[i]);
	}
}