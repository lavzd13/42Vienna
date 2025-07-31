#include "Span.hpp"

/* int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
} */

int main(void) {
	Span	test(10);
	test.addNumber(2);
	test.addNumber(2);
	test.fill(8);
	test.printElements();
	std::cout << std::endl;
	Span	test2 = test;
	Span	test3(test);
	test2.printElements();
	std::cout << std::endl;
	test3.printElements();
	std::cout << std::endl;
	test2.printElements();
	std::cout << std::endl;
	test3.printElements();
	std::cout << std::endl;
	try {
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Testing with const object." << std::endl;
	const Span	testcons(test);
	testcons.printElements();
	std::cout << std::endl;
	std::cout << testcons.shortestSpan();
	std::cout << std::endl;
	std::cout << testcons.longestSpan();
}