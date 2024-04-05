#include "contacts.hpp"

Contacts::Contacts(void){}

Contacts::~Contacts(void){}

std::string	Contacts::get_first_name(void) const {
	return (this->first_name);
};

std::string	Contacts::get_last_name(void) const {
	return (this->last_name);
}

std::string	Contacts::get_nickname(void) const {
	return (this->nickname);
}

std::string	Contacts::get_phone(void) const {
	return (this->phone_num);
}

std::string	Contacts::get_secret(void) const {
	return (this->secret);
}

void	Contacts::set_first_name(std::string str) {
	this->first_name = str;
}

void	Contacts::set_last_name(std::string str) {
	this->last_name = str;
}

void	Contacts::set_nickname(std::string str) {
	this->nickname = str;
}

void	Contacts::set_phone(std::string str) {
	this->phone_num = str;
}

void	Contacts::set_secret(std::string str) {
	this->secret = str;
}