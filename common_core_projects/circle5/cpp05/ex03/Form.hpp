#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

		virtual void	classExecution() const = 0;

	public:
		Form(const std::string& name, int signGrade, int execGrade);
		Form(const Form &copy);
		Form& operator=(const Form &copy);
		virtual ~Form();
		void				beSigned(const Bureaucrat& bure);
		std::string			getName(void) const;
		bool				getSign(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		void				setSign(bool sign);
		void				execute(Bureaucrat const & executor) const;
		class GradeToLowExc: public std::exception {
			virtual const char*	what() const throw();
		};
		class GradeToHighExc: public std::exception {
			virtual const char*	what() const throw();
		};
		class AlreadySignedExc: public std::exception {
			virtual const char*	what() const throw();
		};
		class FormNotSigned: public std::exception {
			virtual const char*	what() const throw();
		};
};

std::ostream& operator<<(std::ostream &o, const Form& form);