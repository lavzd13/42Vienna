#pragma once

#include <iostream>
#include <unistd.h>

class Base {
	private:

	public:
		virtual ~Base();

		Base*	generate(void);
	void	identify(Base* p);
	void 	identify(Base& p);
};
