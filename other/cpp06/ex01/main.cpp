#include "Serializer.hpp"

int main(void) {
	Data *test = new Data;

	test->serial = 5;

	uintptr_t ser = Serializer::serialize(test);
	Data *des = Serializer::deserialize(ser);
	std::cout << test << std::endl;
	std::cout << ser << std::endl;
	std::cout << des << std::endl;
	std::cout << test->serial << std::endl;
	std::cout << des->serial << std::endl;

	delete test;
}