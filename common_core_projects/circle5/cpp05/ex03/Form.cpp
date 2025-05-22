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
	if (_signed)
		throw Form::AlreadySignedExc();
	else if (bure.getGrade() > _signGrade)
		throw Form::GradeToLowExc();
	else
		_signed = true;
}

const char* Form::GradeToLowExc::what() const throw() {
	return "Grade too low!";
}

const char* Form::GradeToHighExc::what() const throw() {
	return "Grade too high!";
}

const char* Form::AlreadySignedExc::what() const throw() {
	return "Form already signed!";
}

const char* Form::FormNotSigned::what() const throw() {
	return "Form is not signed. Sign the form in order to execute it.";
}

std::string	Form::getName() const {
	return _name;
}

bool	Form::getSign() const {
	return _signed;
}

int	Form::getSignGrade() const {
	return _signGrade;
}

int	Form::getExecGrade() const {
	return _execGrade;
}

void	Form::setSign(bool sign) {
	_signed = sign;
}

void	Form::execute(Bureaucrat const & executor) const {
	if (!_signed)
		throw Form::FormNotSigned();
	if (executor.getGrade() > _execGrade) {
		throw Form::GradeToLowExc();
	}
	std::cout << "Bureaucrat " + executor.getName() + " executed " + _name + " form." << std::endl;
	classExecution();
}

std::ostream& operator<<(std::ostream &o, const Form& form) {
	o << "Form " + form.getName() + " with sign grade: " << form.getSignGrade();
	o << " and with execution grade: " << form.getExecGrade();
	if (form.getSign())
		o << " is signed.";
	else
		o << " is not signed.";
	return o;
}
