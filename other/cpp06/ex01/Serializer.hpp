#pragma once

#include <iostream>
#include <stdint.h>

struct Data {
	int	serial;
};

class Serializer {
	private:
		Serializer();
		Serializer& operator=(const Serializer &copy);
		Serializer(const Serializer &copy);
		~Serializer();

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*			deserialize(uintptr_t raw);
};
