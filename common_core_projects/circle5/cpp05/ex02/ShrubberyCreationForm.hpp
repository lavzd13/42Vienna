#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm {
	private:
		std::string		_target;
		void	classExecution() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();
};
