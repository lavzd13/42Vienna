#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default target") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}


RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", copy.getSignGrade(), copy.getExecGrade()){
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm &copy) {
	_target = copy._target;
	setSign(copy.getSign());
	return *this;
}

void	RobotomyRequestForm::classExecution() const {
	unsigned long int			num;
	unsigned long seed = static_cast<unsigned long>(time(0));
	num = seed % 2;
	if (num == 0)
		std::cout << _target << " has been succsefully robotomized." << std::endl;
	else
		std::cout << _target << " couldn't be robotomized, try again." << std::endl;
}
