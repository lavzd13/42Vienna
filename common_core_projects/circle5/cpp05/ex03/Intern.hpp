#pragma once

#include <iostream>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:

	public:
		Intern();
		Intern(const Intern &copy);
		Intern& operator=(const Intern &copy);
		~Intern();

		class InvalidForm: public std::exception {
			virtual const char*	what() const throw();
		};

		Form*	makeForm(std::string form, std::string target);
};