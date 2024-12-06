#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	/* Bureaucrat boban("Boban", 120);
	boban.decrementGrade(12);
	try {
		std::cout << "Decrementing grade 132 by 18." << std::endl;
		boban.decrementGrade(18);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Decrementing grade 150 by 180." << std::endl;
		boban.decrementGrade(180);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Creating Bureaucrat with grade 0." << std::endl;
		Bureaucrat milorad("milorad", 0);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Creating Bureaucrat with grade 151." << std::endl;
		Bureaucrat test("test", 151);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << boban << std::endl; */
	Bureaucrat boban("Boban", 6);
	try {
	Bureaucrat boban("Boban", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Form	vote("Galsanje", 5, 3);
	try {
		vote.beSigned(boban);
		if (vote.getSign() == true)
			std::cout << "Form succesfully signed." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}