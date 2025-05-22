#include "iter.hpp"

template <typename T>
void	f(T& a) {
	std::cout << a << std::endl;
}

int main (void) {
	int arr[] = {1, 2, 3, 4, 5};
	std::string arr2[] = {"string1", "string2", "string3", "string4", "string5"};

	iter(arr, 5, f);
	iter(arr2, 5, f);
}