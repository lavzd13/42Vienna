#include "Intern.hpp"
#include <cstring>

static Form*	PresidentCreate(std::string target);
static Form*	RobotCreate(std::string target);
static Form*	ShroomCreate(std::string target);

Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(const Intern& copy) {
	*this = copy;
}

Intern&	Intern::operator= (const Intern& copy) {
	(void)copy;
	return *this;
}

const char* Intern::InvalidForm::what() const throw() {
	std::cout << "Unknown type of form. Please enter valid form name." << std::endl;
	std::cout << "Valid forms: " << std::endl << "\033[1;32mpresidental pardon" << std::endl <<
	"robotomy request" << std::endl << "shrubery creation\033[0m";
	return "";
}

static Form*	PresidentCreate(std::string target) {
	std::cout << "Intern creates PresidentalPardonForm." << std::endl;
	return new PresidentialPardonForm(target);
}

static Form*	RobotCreate(std::string target) {
	std::cout << "Intern creates RobotomyRequestForm." << std::endl;
	return new RobotomyRequestForm(target);
}

static Form*	ShroomCreate(std::string target) {
	std::cout << "Intern creates ShrubberyCreationForm." << std::endl;
	return new ShrubberyCreationForm(target);
}

Form*	Intern::makeForm(std::string form, std::string target) {
	Form* (*CreationFuncs[3])(std::string) = {PresidentCreate, RobotCreate, ShroomCreate};
	std::string forms[3] = {"presidental pardon", "robotomy request", "shrubery creation"};

	for (int i = 0; i < 3; i++) {
		if (form == forms[i])
			return (CreationFuncs[i](target));
	}
	throw Intern::InvalidForm();
}
