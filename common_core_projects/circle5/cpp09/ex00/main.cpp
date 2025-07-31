#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {


	if (argc != 2) {
		std::cout << "Error: invalid filename provided." << std::endl;
		return 1;
	}

	std::ifstream	csv_file("data.csv");

	if (!csv_file) {
		std::cout << "Error: could not open data.csv." << std::endl;
		return 1;
	}

	std::ifstream	input_file(argv[1]);

	if (!input_file) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcointExchange	bit;

	bit.collect_data(csv_file);
	bit.parse_input_file(input_file);

	return 0;
}
