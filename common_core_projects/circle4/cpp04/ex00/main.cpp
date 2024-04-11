#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) {
std::cout << std::endl << "---------------Subject tests------------------" << std::endl;
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
}
std::cout << "----------------------------------------------" << std::endl;
std::cout << std::endl << "-----------------Mine tests-------------------" << std::endl;
{
	Cat	c;
	Dog	d;
	c.makeSound();
	c.getType();
	d.makeSound();
	d.getType();
}
std::cout << "----------------------------------------------" << std::endl;
std::cout << std::endl << "-----------Subject modified tests-------------" << std::endl;
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	delete meta;
	delete i;
}
std::cout << "----------------------------------------------" << std::endl;
}
