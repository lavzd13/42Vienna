#include <iostream>

int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPtr = &str;
	std::string &stringRef = str;
	std::cout << "Address of a str: " << &str << std::endl;
	std::cout << "Address of a ptr: " << stringPtr << std::endl;
	std::cout << "Address of a ref: " << &stringRef << std::endl;
	std::cout << "Value of a str: " << str << std::endl;
	std::cout << "Value of a ptr: " << *stringPtr << std::endl;
	std::cout << "Value of a ref: " << stringRef << std::endl;
}