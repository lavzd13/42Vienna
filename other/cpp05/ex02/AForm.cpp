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
	_signed(false),
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
	return "AForm: grade too low!";
}

const char* AForm::GradeToHighExc::what() const throw() {
	return "AForm: grade too high!";
}

const char* AForm::AlreadySignedExc::what() const throw() {
	return "AForm: form already signed!";
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
	if (executor.getGrade() > _execGrade) {
		throw AForm::GradeToLowExc();
	}
	classExecution();
}

std::ostream& operator<<(std::ostream &o, const AForm& form) {
	o << "Form " + form.getName() + " with sign grade: " << form.getSignGrade();
	o << " and with execution grade: " << form.getExecGrade();
	if (form.getSign())
		o << " is signed." << std::endl;
	else
		o << " is not signed." << std::endl;
	return o;
}
