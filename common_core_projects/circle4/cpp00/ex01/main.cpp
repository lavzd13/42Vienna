#include "phonebook.hpp"
#include "contacts.hpp"

int	main(void) {
	PhoneBook	pb;
	std::string	input;

	input = "";
	std::cout << "Enter the command (ADD, SEARCH or EXIT): ";
	while (std::getline(std::cin, input))
	{
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else if (input != "" && pb.only_spaces(input))
			std::cout << std::endl << input + " is not valid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		std::cout << std::endl << "Enter the command: ";
	}
	return (0);
}