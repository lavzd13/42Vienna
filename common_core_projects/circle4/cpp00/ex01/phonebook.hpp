#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include "contacts.hpp"

#define RESET	"\033[0m"
#define GRAY	"\033[1m\033[90m"
#define RED		"\033[1m\033[31m"
#define GREEN	"\033[1m\033[32m"
#define YELLOW	"\033[1m\033[33m"
#define BLUE	"\033[1m\033[34m"
#define MAGENTA	"\033[1m\033[35m"
#define CYAN	"\033[1m\033[36m"
#define WHITE	"\033[1m\033[37m"

class	PhoneBook
{
	private:
		Contacts	cont[8];
		int			index;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void		add(void);
		void		search(void);
		void		print(void);
		bool		phone_check(std::string str);
		bool		is_ascii(std::string str);
		std::string	check_length(std::string str);
		int			is_alpha(std::string str);
		int			only_spaces(std::string str);
};

#endif