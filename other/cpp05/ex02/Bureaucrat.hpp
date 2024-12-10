#pragma once

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"

#define MAX 1
#define MIN 150

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

		class GradeToLowExc: public std::exception {
			virtual const char*	what() const throw();
		};

		class GradeToHighExc: public std::exception {
			virtual const char*	what() const throw();
		};
		class AlreadySignedExc: public std::exception {
			virtual const char*	what() const throw();
		};
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat &copy);
		~Bureaucrat();
		const std::string&	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(int value);
		void				decrementGrade(int value);
		void				signForm(AForm& form);

};

std::ostream&	operator<<(std::ostream &o, const Bureaucrat &biro);