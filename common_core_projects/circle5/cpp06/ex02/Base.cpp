#include "Base.hpp"
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base*	Base::generate(void) {
	srand(static_cast<unsigned long int>(time(0)));

	int	num = rand() % 3;

	switch (num) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
	}
	return (NULL);
}

void	Base::identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer: Object A identified." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer: Object B identified." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer: Object C identified." << std::endl;
	else
		std::cout << "Pointer: Unkown object." << std::endl;
}

void 	Base::identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference: Object A identified." << std::endl;
	}
	catch (std::exception& e) {
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference: Object B identified." << std::endl;
	}
	catch (std::exception& e) {
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference: Object C identified." << std::endl;
	}
	catch (std::exception& e) {
	}
}
