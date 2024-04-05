#include "phonebook.hpp"

PhoneBook::PhoneBook(void) {
	this->index = 0;
	std::cout << std::endl << "Welcome to the PhoneBook" << std::endl;
};

PhoneBook::~PhoneBook(void) {
	std::cout << std::endl << "Goodbye!" << std::endl;
};

bool	PhoneBook::phone_check(std::string str) {
	size_t	i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	PhoneBook::is_ascii(std::string str) {
	size_t	i;

	i = 0;
	while (i < str.length())
	{
		if (str[i] < 0 || str[i] > 127 || str[i] == '\t')
			return (false);
		i++;
	}
	return (true);
}

int	PhoneBook::is_alpha(std::string str) {
	size_t i = 0;

	while (i < str.length()) {
		if (!isalpha(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	PhoneBook::only_spaces(std::string str) {
	size_t	i = 0;

	while (i < str.length()) {
		if (isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	PhoneBook::add() {
	std::string	str;

	str = "";
	if (this->index % 8 == 0 && this->index != 0)
		std::cout << RED << "Overwriting the data of the oldest entry" << RESET << std::endl;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter the first name: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (!is_alpha(str))
			{
				str = "";
				std::cout << CYAN << "Currently we accept only alphabetical letters for the name." << RESET << std::endl;
				continue;
			}
			else {
				if (!only_spaces(str)) {
					str = "";
					std::cout << RED << "You need at least one letter." << RESET << std::endl;
					continue;
				}
				this->cont[index % 8].set_first_name(str);
			}
		}
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter the last name: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (!is_alpha(str))
			{
				str = "";
				std::cout << CYAN << "Currently we accept only alphabetical letters for the lastname." << RESET << std::endl;
				continue;
			}
			else {
				if (!only_spaces(str)) {
					str = "";
					std::cout << RED << "You need at least one letter." << RESET << std::endl;
					continue;
				}
				this->cont[index % 8].set_last_name(str);
			}
		}
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter nickname: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (!is_alpha(str))
			{
				str = "";
				std::cout << CYAN << "Currently we accept only alphabetical letters for the nickname." << RESET << std::endl;
				continue;
			}
			else {
				if (!only_spaces(str)) {
					str = "";
					std::cout << RED << "You need at least one letter." << RESET << std::endl;
					continue;
				}
				this->cont[index % 8].set_nickname(str);
			}
		}
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter phone number: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (!phone_check(str))
			{
				str = "";
				std::cout << RED << "Phone number can only contain digits and preceding plus." << RESET << std::endl;
				continue;
			}
			else {
				if (str.length() > 21) {
					str = "";
					std::cout << RED << "More than 21 digits for the phone number where do you work in CIA?" << RESET << std::endl;
					continue;
				}
				this->cont[index % 8].set_phone(str);
			}
		}
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (!is_alpha(str))
			{
				str = "";
				std::cout << CYAN << "Describe your darkest secret with words only, without numbers or special chars." << RESET << std::endl;
				continue;
			}
			else {
				if (!only_spaces(str)) {
					str = "";
					std::cout << RED << "You need at least one letter." << RESET << std::endl;
					continue;
				}
				this->cont[index % 8].set_secret(str);
			}
		}
	}
	if (cont[index % 8].get_secret().size() > 0)
		this->index++;
}

std::string	PhoneBook::check_length(std::string str) {
	if (str.size() > 10) {
		str.resize(10);
		str[10 - 1] = '.';
	}
	return (str);
}

void	PhoneBook::search(void) {

	if (!this->cont[0].get_first_name().size()) {
		std::cout << "No saved contacts." << std::endl;
		return ;
	}
	std::cout << GRAY << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << RESET <<std::endl;
	for (int i = 1; i < 9 && this->cont[i - 1].get_first_name().size(); i++) {
		std::cout << GRAY << "|" << RESET << WHITE << std::setw(10) << std::right << i << RESET << GRAY << "|" << RESET;
		std::cout << CYAN << std::setw(10) << std::right << check_length(cont[i - 1].get_first_name()) << RESET << GRAY "|" << RESET;
		std::cout << CYAN << std::setw(10) << std::right << check_length(cont[i - 1].get_last_name()) << GRAY "|" << RESET;
		std::cout << CYAN << std::setw(10) << std::right << check_length(cont[i - 1].get_nickname()) << GRAY "|" << RESET;
		std::cout << std::endl;
	}
	print();
}

void	PhoneBook::print(void) {
	std::string	str;
	int	num;

	str = "";
	std::cout << std::endl;
	while (!std::cin.eof())
	{
		std::cout << std::endl << "Enter the index of desired person: ";
		std::getline(std::cin, str);
		std::stringstream	ss(str);
		if (phone_check(str) && ss >> num)
		{
			if (num >= 1 && num <= 8 && str.size() == 1)
			{
				if (cont[num - 1].get_first_name().size() <= 0)
					std::cout << "Contact with that index does not exist." << std::endl;
				else
					break ;
			}
			else
			{
				std::cout << "Please enter the valid index (1-8)." << std::endl;
				std::cin.clear();
			}
		}
		else if (!std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "Please enter a valid integer." << std::endl;
			std::cin.clear();
		}
	}
	if (std::cin.eof())
		return ;
	std::cout << std::endl;
	std::cout << "Getting the data..." << std::endl;
	std::cout << std::endl;
	std::cout << "First name: " + cont[num - 1].get_first_name() << std::endl;
	std::cout << "Last name: " + cont[num - 1].get_last_name() << std::endl;
	std::cout << "Nickname: " + cont[num - 1].get_nickname() << std::endl;
	std::cout << "Phone number: " + cont[num - 1].get_phone() << std::endl;
	std::cout << "Darkest secret: " + cont[num - 1].get_secret() << std::endl;
	std::cin.clear();
}