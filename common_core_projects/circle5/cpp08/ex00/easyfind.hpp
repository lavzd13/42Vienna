#pragma once

#include <iostream>
#include <algorithm>

template <typename T>

void	easyfind(const T& cont, int i) {
	typename T::const_iterator	iter = std::find(cont.begin(), cont.end(), i);

	if (iter != cont.end()) {
		std::cout << "Element " << i << " was found at index " << std::distance(cont.begin(), iter) << std::endl;
	}
	else {
		throw std::out_of_range("Couldn't find the the given element");
	}
}