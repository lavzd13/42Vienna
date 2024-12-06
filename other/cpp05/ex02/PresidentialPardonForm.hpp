#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		std::string	_target;
		virtual void	classExecution() const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();
};
