#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>

class Contacts
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_num;
		std::string	secret;
	public:
		Contacts(void);
		~Contacts(void);
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phone(void) const;
		std::string	get_secret(void) const;
		void	set_first_name(std::string str);
		void	set_last_name(std::string str);
		void	set_nickname(std::string str);
		void	set_phone(std::string str);
		void	set_secret(std::string str);
};
#endif