#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void) {
	Bureaucrat	bure("Dagada",5);
	Intern	saban;
	Form* proba;
	try {
		proba = saban.makeForm("robotomy request", "ALO BRE");
		bure.signForm(*proba);
		bure.executeForm(*proba);
		delete proba;
	}
	catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	PresidentialPardonForm	pres("Patron");
	RobotomyRequestForm		robot("Robot");
	ShrubberyCreationForm	shroom("Gudranje");

	try {
		bure.signForm(pres);
		bure.signForm(robot);
		//bure.signForm(shroom);
		bure.executeForm(pres);
		bure.executeForm(robot);
		bure.executeForm(shroom);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << robot << std::endl;
}