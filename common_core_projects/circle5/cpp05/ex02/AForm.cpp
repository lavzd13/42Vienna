#include "AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade) :
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade) {
	if (signGrade > MIN || execGrade > MIN)
		throw AForm::GradeToLowExc();
	else if (signGrade < MAX || execGrade < MAX)
		throw AForm::GradeToHighExc();
}

AForm::~AForm() {
}

AForm::AForm(const AForm &copy) :
	_name(copy._name),
	_signed(copy.getSign()),
	_signGrade(copy._signGrade),
	_execGrade(copy._execGrade) {
}

AForm& AForm::operator= (const AForm &copy) {
	(void)copy;
	return *this;
}

void	AForm::beSigned(const Bureaucrat &bure) {
	if (_signed)
		throw AForm::AlreadySignedExc();
	else if (bure.getGrade() > _signGrade)
		throw AForm::GradeToLowExc();
	else
		this->_signed = true;
}

const char* AForm::GradeToLowExc::what() const throw() {
	return "Grade too low!";
}

const char* AForm::GradeToHighExc::what() const throw() {
	return "Grade too high!";
}

const char* AForm::AlreadySignedExc::what() const throw() {
	return "Form already signed!";
}

const char* AForm::FormNotSigned::what() const throw() {
	return "Form is not signed. Sign the form in order to execute it.";
}

std::string	AForm::getName() const {
	return this->_name;
}

bool	AForm::getSign()const {
	return this->_signed;
}

int	AForm::getSignGrade() const {
	return this->_signGrade;
}

int	AForm::getExecGrade() const {
	return this->_execGrade;
}

void	AForm::setSign(bool sign) {
	_signed = sign;
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (!_signed)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > _execGrade) {
		throw AForm::GradeToLowExc();
	}
	std::cout << "Bureaucrat " + executor.getName() + " executed " + _name + " form." << std::endl;
	classExecution();
}

std::ostream& operator<<(std::ostream &o, const AForm& form) {
	o << "Form " + form.getName() + " with sign grade: " << form.getSignGrade();
	o << " and with execution grade: " << form.getExecGrade();
	if (form.getSign())
		o << " is signed.";
	else
		o << " is not signed.";
	return o;
}
