#pragma once

#include <iostream>

class Brain {
	private:
		std::string	*_ideas;
	public:
		Brain();
		Brain(const Brain &copy);
		Brain& operator=(const Brain &copy);
		~Brain();
		std::string*	getIdeas(void) const;
};
