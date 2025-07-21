#ifndef BITCOINTEXCHANGE_HPP
#define BITCOINTEXCHANGE_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <map>

class	BitcointExchange {
	private:
		std::map<std::string, float>	_data_map;

		int		day_month_match(int month, int day, bool is_leap);
		int		parse_date(std::string &date);
		int		parse_value(std::string &value);
		void	database_check(std::string &date, std::string &value);
		void	look_for_another_date(std::string &date, std::string &value);
	public:
		BitcointExchange();
		BitcointExchange& operator=(const BitcointExchange &copy);
		BitcointExchange(const BitcointExchange &copy);
		~BitcointExchange();
		void	collect_data(std::ifstream &data_file);
		void	parse_input_file(std::ifstream &input_file);
};

#endif