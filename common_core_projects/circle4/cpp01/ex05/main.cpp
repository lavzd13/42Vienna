#include "Harl.hpp"

void	printAll(Harl *test) {
	test->complain("level1");
	test->complain("level2");
	test->complain("level3");
	test->complain("level4");
}

int	main(void) {
	Harl	test;
	std::string	i = "";
	while (i == "")
	{
		std::cout << "Please enter level(1-4) or \"all\": ";
		std::getline(std::cin, i);
		if (i != "1" && i != "2" && i != "3" && i != "4" && i != "all") {
			std::cout << "Please enter a valid integer value from range 1-4" << std::endl;
			std::cin.clear();
			i = "";
			continue;
		}
		if (i == "all") {
			printAll(&test);
			break ;
		}
		test.complain("level" + i);
		std::cin.clear();
	}
}