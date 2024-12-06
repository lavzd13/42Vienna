#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	Bureaucrat	bure("Boban", 5);
	PresidentialPardonForm	pres("Patron");
	RobotomyRequestForm		robot("Robot");
	try {
		bure.signForm(pres);
		pres.execute(bure);
		robot.execute(bure);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	/* try {
		bure.signForm(pres);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		bure.signForm(robot);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	} */
}