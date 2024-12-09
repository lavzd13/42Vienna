#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", copy.getSignGrade(), copy.getExecGrade()) {
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm &copy) {
	_target = copy._target;
	setSign(copy.getSign());
	return *this;
}

void	ShrubberyCreationForm::classExecution() const {
	std::string filename = _target + "_shrubbery.txt";
	std::ofstream ofs(filename.c_str(), std::ofstream::out);

	if (ofs.is_open()) {
		ofs <<"                *"<< std::endl;
		ofs <<"               /o\\"<< std::endl;
		ofs <<"              /o*o\\"<< std::endl;
		ofs <<"             /o*o*o\\"<< std::endl;
		ofs <<"            /o*o*o*o\\"<< std::endl;
		ofs <<"           /o*o*o*o*o\\"<< std::endl;
		ofs <<"          /o*o*o*o*o*o\\"<< std::endl;
		ofs <<"         /o*o*o*o*o*o*o\\"<< std::endl;
		ofs <<"        /o*o*o*o*o*o*o*o\\"<< std::endl;
		ofs <<"       /o*o*o*o*o*o*o*o*o\\"<< std::endl;
		ofs <<"      /o*o*o*o*o*o*o*o*o*o\\"<< std::endl;
		ofs <<"     /o*o*o*o*o*o*o*o*o*o*o\\"<< std::endl;
		ofs <<"    /o*o*o*o*o*o*o*o*o*o*o*o\\"<< std::endl;
		ofs <<"   /o*o*o*o*o*o*o*o*o*o*o*o*o\\"<< std::endl;
		ofs <<"  /o*o*o*o*o*o*o*o*o*o*o*o*o*o\\"<< std::endl;
		ofs <<" /o*o*o*o*o*o*o*o*o*o*o*o*o*o*o\\"<< std::endl;
		ofs <<"/o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o\\"<< std::endl;
		ofs <<"			  |||"<< std::endl;
		ofs <<"			  |||"<< std::endl;
		ofs <<"			 /|||\\"<< std::endl;
		ofs <<"			 |||||"<< std::endl;
		ofs <<"        	/|||||\\"<< std::endl;
		ofs <<"       	   /|||||||\\"<< std::endl;
		ofs <<"          /|||||||||\\"<< std::endl;
		ofs <<"         /___________\\"<< std::endl;
		ofs.close();
	}
	else {
		std::cerr << "Can't open the file." << std::endl;
	}
}
