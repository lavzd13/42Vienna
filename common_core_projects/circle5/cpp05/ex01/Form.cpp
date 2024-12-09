#include "Form.hpp"

Form::Form(const std::string& name, int signGrade, int execGrade) :
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade) {
	if (signGrade > MIN || execGrade > MIN)
		throw Form::GradeToLowExc();
	else if (signGrade < MAX || execGrade < MAX)
		throw Form::GradeToHighExc();
}

Form::~Form() {
}

Form::Form(const Form &copy) :
	_name(copy._name),
	_signed(copy.getSign()),
	_signGrade(copy._signGrade),
	_execGrade(copy._execGrade) {
}

Form& Form::operator= (const Form &copy) {
	(void)copy;
	return *this;
}

void	Form::beSigned(const Bureaucrat &bure) {
	if (this->_signed) {
		std::cout << "Form: This form is already signed." << std::endl;
	}
	else if (bure.getGrade() > _signGrade)
		throw Form::GradeToLowExc();
	else
		this->_signed = true;
}

const char* Form::GradeToLowExc::what() const throw() {
	return "Form: grade too low!";
}

const char* Form::GradeToHighExc::what() const throw() {
	return "Form: grade too high!";
}

std::string	Form::getName() const {
	return this->_name;
}

bool	Form::getSign()const {
	return this->_signed;
}

int	Form::getSignGrade() const {
	return this->_signGrade;
}

int	Form::getExecGrade() const {
	return this->_execGrade;
}

std::ostream& operator<<(std::ostream &o, const Form& form) {
	o << "Form " + form.getName() + " with sign grade: " << form.getSignGrade();
	o << " and with execution grade: " << form.getExecGrade();
	if (form.getSign())
		o << " is signed." << std::endl;
	else
		o << " is not signed." << std::endl;
	return o;
}
