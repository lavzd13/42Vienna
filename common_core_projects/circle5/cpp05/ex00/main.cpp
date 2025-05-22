#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat boban("Boban", 132);
	try {
		boban.incrementGrade(12);
		std::cout << boban.getGrade() << std::endl;
	}
	catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
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
	std::cout << boban << std::endl << std::endl;
	Bureaucrat milan("Milan", 3);
	std::cout << milan << std::endl;
	std::cout << "Incrementing Bureaucrat grade by 1." << std::endl;
	milan.incrementGrade(1);
	std::cout << milan << std::endl;
}