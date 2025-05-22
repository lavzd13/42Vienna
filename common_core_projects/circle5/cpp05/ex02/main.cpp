#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	Bureaucrat	bure("Dagada",5);
	PresidentialPardonForm	pres("Patron");
	RobotomyRequestForm		robot("Cika Velja");
	ShrubberyCreationForm	shroom("Gudranje");

	try {
		bure.signForm(pres);
		bure.signForm(robot);
		bure.signForm(shroom);
		bure.executeForm(pres);
		bure.executeForm(robot);
		bure.executeForm(shroom);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << robot << std::endl;
}