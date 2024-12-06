#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

		class GradeToLowExc: public std::exception {
			virtual const char*	what() const throw();
		};
		class GradeToHighExc: public std::exception {
			virtual const char*	what() const throw();
		};
		class AlreadySignedExc: public std::exception {
			virtual const char*	what() const throw();
		};
		virtual void	classExecution() const = 0;

	public:
		AForm(const std::string& name, int signGrade, int execGrade);
		AForm(const AForm &copy);
		AForm& operator=(const AForm &copy);
		~AForm();
		void				beSigned(const Bureaucrat& bure);
		std::string			getName(void) const;
		bool				getSign(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		void				setSign(bool sign);
		void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat& biro);