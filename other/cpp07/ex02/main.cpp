#include <iostream>
#include "Array.hpp"

template <typename T>
void	print(T printable) {
	std::cout << printable << std::endl;
}

void	newline() {
	std::cout << std::endl;
}

int main(void) {
	Array<int> emptyarr;
	try {
		emptyarr[0];
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	Array<std::string>	strarr(5);

	strarr[0] = "str1";
	strarr[1] = "str2";
	strarr[2] = "str3";
	strarr[3] = "str4";
	strarr[4] = "str5";

	newline();
	print("Accessing the element of the array with [] operator.");
	std::cout << strarr[1] << std::endl;
	Array<std::string>	copy = strarr;
	Array<std::string>	copyconst(strarr);
	newline();
	print("Printing the values of the object created with copy operator.");
	print(copy[1]);
	print(copy.size());
	newline();
	print("Printing the values of the object created with copy constructor.");
	print(copyconst[1]);
	print(copyconst.size());
}