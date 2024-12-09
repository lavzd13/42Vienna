#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade > MIN)
		throw Bureaucrat::GradeToLowExc();
	else if (grade < MAX)
		throw Bureaucrat::GradeToHighExc();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	*this = copy;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat &copy) {
	this->_grade = copy._grade;
	return *this;
}

void Bureaucrat::incrementGrade(int value) {
	if (this->_grade - value < 1)
		throw Bureaucrat::GradeToHighExc();
	else
		this->_grade -= value;
}

void Bureaucrat::decrementGrade(int value) {
	if (this->_grade + value > 150)
		throw Bureaucrat::GradeToLowExc();
	else
		this->_grade += value;
}

const std::string& Bureaucrat::getName(void) const {
	return this->_name;
}

int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

const char* Bureaucrat::GradeToLowExc::what() const throw() {
	return "Bureaucrat grade too low!";
}

const char* Bureaucrat::GradeToHighExc::what() const throw() {
	return "Bureaucrat grade too high!";
}

void	Bureaucrat::signForm(Form& form) {
	if (form.getSign()) {
		std::cout << "Bureaucrat " + this->_name + " couldn't sign " + form.getName();
		std::cout << " because the form is already signed." << std::endl;
	}
	else if (this->_grade > form.getSignGrade()) {
		std::cout << "Bureaucrat " + this->_name + " couldn't sign " + form.getName();
		std::cout << " because his grade is too low." << std::endl;
	}
	else {
		form.beSigned(*this);
		std::cout << "Bureaucrat " + this->_name + " signed " + form.getName() + "." << std::endl;
	}
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat& biro) {
	o << biro.getName() + ", bureaucrat grade " << biro.getGrade();
	return o;
}
