#pragma once

#include <iostream>

class Base {
	private:

	public:
		virtual ~Base();

		Base*	generate(void);
	void	identify(Base* p);
	void 	identify(Base& p);
};
