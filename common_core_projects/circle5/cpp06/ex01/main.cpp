#include "Serializer.hpp"

int main(void) {
	Data *test = new Data;

	test->serial = 5;

	uintptr_t ser = Serializer::serialize(test);
	Data *des = Serializer::deserialize(ser);
	std::cout << "Original pointer: " << test << std::endl;
	std::cout << std::endl;
	std::cout << "Serialized uintptr_t: " << ser << std::endl;
	std::cout << std::endl;
	std::cout << "Deserialized uintptr_t: " << des << std::endl;
	std::cout << std::endl;
	std::cout << "Valued of orginal: " << test->serial << std::endl;
	std::cout << std::endl;
	std::cout << "Value of object created using deserialization: " << des->serial << std::endl;

	delete test;
}