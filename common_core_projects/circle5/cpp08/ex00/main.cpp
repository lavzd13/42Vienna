#include "easyfind.hpp"
#include <vector>
#include <list>
#include <set>
#include <deque>

int main(void) {
	std::cout << "Testing with const vector container." << std::endl;

	const std::vector<int>	testconst(4, 10);

	easyfind(testconst, 10);
	std::cout << std::endl;


	std::vector<int>	test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);

	std::cout << "Testing with vector container." << std::endl;
	try {
		easyfind(test, 1);
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::list<int>	test2;

	test2.push_back(1);
	test2.push_back(2);
	test2.push_back(3);
	test2.push_back(4);
	test2.push_back(5);

	std::cout << "Testing with list container." << std::endl;
	try {
		easyfind(test2, 2);
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::set<int>	test3;

	test3.insert(1);
	test3.insert(2);
	test3.insert(3);
	test3.insert(4);
	test3.insert(5);

	std::cout << "Testing with set container." << std::endl;
	try {
		easyfind(test3, 3);
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::deque<int>	test4;

	test4.push_back(1);
	test4.push_back(2);
	test4.push_back(3);
	test4.push_back(4);
	test4.push_back(5);

	std::cout << "Testing with deque container." << std::endl;
	try {
		easyfind(test4, 6);
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}