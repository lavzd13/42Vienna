#include "BitcoinExchange.hpp"

BitcointExchange::BitcointExchange() {}

BitcointExchange::~BitcointExchange() {}

BitcointExchange::BitcointExchange(const BitcointExchange &copy) {
	*this = copy;
}

BitcointExchange& BitcointExchange::operator= (const BitcointExchange &copy) {
	_data_map = copy._data_map;
	return *this;
}

// Function for validating days in month
int	BitcointExchange::day_month_match(int month, int day, bool is_leap) {
	if (!is_leap && month == 2 && day > 28)
		return 1;
	if (is_leap && month == 2 && day > 29)
		return 1;
	if ((month == 2 || month == 4 || month == 6
		|| month == 9 || month == 11) && day > 30) {
		return 1;
	}
	return 0;
}

// Function for parsing date of input.txt file
int	BitcointExchange::parse_date(std::string &date) {
	date.erase(0, date.find_first_not_of(" \t"));
	date.erase(date.find_last_not_of(" \t") + 1);

	if (date == "date")
		return 0;

	std::stringstream	ss(date);
	std::string			s_year, s_month, s_day;

	if (!std::getline(ss, s_year, '-'))
		return 1;
	if (!std::getline(ss, s_month, '-'))
		return 1;
	if (!std::getline(ss, s_day, '-'))
		return 1;

	int	year = std::atoi(s_year.c_str());
	int	month = std::atoi(s_month.c_str());
	int	day = std::atoi(s_day.c_str());
	bool	is_leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? true : false;

	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return 1;
	if (day_month_match(month, day, is_leap) == 1)
		return 1;

	return 0;
}

int	BitcointExchange::parse_value(std::string &value) {
	value.erase(0, value.find_first_not_of(" \t"));
	value.erase(value.find_last_not_of(" \t") + 1);

	if (value == "value")
		return 0;

	long		value_int = std::atol(value.c_str());
	float		value_flo = std::atof(value.c_str());

	if (value_flo <= 0 || value_int >= 1000 || value_flo >= 1000) {
		if (value_flo <= 0)
			std::cout << "Error: not a positive integer." << std::endl;
		if (value_flo >= 1000 || value_int >= 1000)
			std::cout << "Error: number is too large." << std::endl;
		return 1;
	}
	return 0;
}

void	BitcointExchange::look_for_another_date(std::string &date, std::string &value) {
	std::stringstream	ss(date);
	std::string			s_year, s_month, s_day;

	// Cutting date to y,m,d so that we can convert it to int.
	if (!std::getline(ss, s_year, '-'))
		return;
	if (!std::getline(ss, s_month, '-'))
		return;
	if (!std::getline(ss, s_day, '-'))
		return;

	// Converting y,m,d from str to int for easier search and usage.
	int	i_year = std::atoi(s_year.c_str());
	int	i_month = std::atoi(s_month.c_str());
	int	i_day = std::atoi(s_day.c_str());

	// Using reverse iterator for map and slicing it->first into y,m,d
	std::map<std::string, float>::reverse_iterator	rit;

	for (rit = _data_map.rbegin(); rit != _data_map.rend(); ++rit) {
		std::stringstream	ss(rit->first);
		std::string			data_year, data_month, data_day;

		// Cutting date to y,m,d so that we can convert it to int.
		if (!std::getline(ss, data_year, '-'))
			return;
		if (!std::getline(ss, data_month, '-'))
			return;
		if (!std::getline(ss, data_day, '-'))
			return;
		// Converting y,m,d from str to int for easier search and usage.
		int	d_year = std::atoi(data_year.c_str());
		int	d_month = std::atoi(data_month.c_str());
		int	d_day = std::atoi(data_day.c_str());

		if (i_year == d_year) {
			if (i_month == d_month) {
				if (i_day > d_day) {
					std::cout << date + " => " + value + " => " << std::atof(value.c_str()) * rit->second << std::endl;
					return;
				}
			}
			else if (i_month > d_month) {
				std::cout << date + " => " + value + " => " << std::atof(value.c_str()) * rit->second << std::endl;
				return;
			}
		}
		else if (i_year > d_year) {
			std::cout << date + " => " + value + " => " << std::atof(value.c_str()) * rit->second << std::endl;
			return;
		}
	}
	std::cout << "Value for date \"" + date + "\" doesn't exist in our database. Try some more recent date." << std::endl;
}

void	BitcointExchange::database_check(std::string &date, std::string &value) {
	date.erase(0, date.find_first_not_of(" \t"));
	date.erase(date.find_last_not_of(" \t") + 1);
	value.erase(0, value.find_first_not_of(" \t"));
	value.erase(value.find_last_not_of(" \t") + 1);


	std::map<std::string, float>::iterator	it;
	std::map<std::string, float>::reverse_iterator	r_it;

	it = _data_map.find(date);
	if (it != _data_map.end()) {
		std::cout << date + " => " + value + " => " << std::atof(value.c_str()) * it->second << std::endl;
		return;
	}
	else if (date == "date")
		std::cout << date + " | " + value << std::endl;
	else {
		look_for_another_date(date, value);
	}
}

// Function for parsing input.txt file
void	BitcointExchange::parse_input_file(std::ifstream &input_file) {
	std::string	line;

	while (std::getline(input_file, line)) {
		std::stringstream	ss(line);
		std::string			date, value;

		if (!std::getline(ss, date, '|')) {
			std::cout << "Error: no date in input file." << std::endl;
			continue;
		}
		if (!std::getline(ss, value, '|')) {
			std::cout << "Error: bad input => " + line << std::endl;
			continue;
		}
		if (parse_date(date) == 1 || parse_value(value) == 1) {
			if (parse_date(date) == 1)
				std::cout << "Error: bad input => " + line << std::endl;
		}
		else
			database_check(date, value);
	}
}

// Function for extracting data from csv file and storing it in map
void	BitcointExchange::collect_data(std::ifstream &data_file) {
	std::string	line;

	if (!std::getline(data_file, line)) {
		std::cout << "Error: failed to read from data.csv" << std::endl;
		return;
	}
	while (std::getline(data_file, line)) {
		std::stringstream	ss(line);
		std::string			date, value;

		if (!std::getline(ss, date, ',')) {
			std::cout << "Error: invalid format in csv file => " + line << std::endl;
			return;
		}
		if (!std::getline(ss, value, ',')) {
			std::cout << "Error: invalid format in csv file => " + line << std::endl;
			return;
		}
		_data_map[date] = std::atof(value.c_str());
	}
}