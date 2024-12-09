#pragma once

#include <iostream>
#include <fstream>
#include "Form.hpp"


class ShrubberyCreationForm : public Form {
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
