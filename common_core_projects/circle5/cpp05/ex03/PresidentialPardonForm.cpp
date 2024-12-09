#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentalPardonForm", 25, 5), _target("default target"){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("PresidentalPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form("PresidentalPardonForm", copy.getSignGrade(), copy.getExecGrade()) {
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm &copy) {
	_target = copy._target;
	setSign(copy.getSign());
	return *this;
}

void	PresidentialPardonForm::classExecution() const {
	std::cout << _target << " has been pardoned Zaphod Beeblebrox." << std::endl;
}
