#pragma once

#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"

#define MAX 1
#define MIN 150

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat &copy);
		~Bureaucrat();
		const std::string&	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(int value);
		void				decrementGrade(int value);
		void				signForm(Form& form);
		void				executeForm(Form const& form);

		class GradeToLowExc: public std::exception {
			virtual const char*	what() const throw();
		};

		class GradeToHighExc: public std::exception {
			virtual const char*	what() const throw();
		};
		class AlreadySignedExc: public std::exception {
			virtual const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &o, const Bureaucrat &biro);
