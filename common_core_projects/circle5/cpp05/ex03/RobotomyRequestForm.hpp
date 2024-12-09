#pragma once

#include <iostream>
#include <stdlib.h>
#include "Form.hpp"

class RobotomyRequestForm : public Form {
	private:
		std::string	_target;
		virtual void	classExecution() const;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
};
