#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void) {
std::cout << std::endl << "---------------Subject tests------------------" << std::endl;
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	j->makeSound();
	std::cout << j->getType() << std::endl;
	i->makeSound();
	std::cout << i->getType() << std::endl;
	delete j;//should not create a leak
	delete i;
}
std::cout << "----------------------------------------------" << std::endl;
std::cout << std::endl << "-----------------EX01 tests-------------------" << std::endl;
{
	Animal *arr[6];
	for (int i = 0; i < 6; i++) {
		if (i < 3)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}
	std::cout << std::endl << "Deconstructors" << std::endl << std::endl;
	for (int i = 0; i < 6; i++)
		delete arr[i];

}
std::cout << "----------------------------------------------" << std::endl;
{
	Dog	dzeki;
	Cat	srecko;

	Dog	dzekiCopy(dzeki);
	Cat	sreckoCopy(srecko);

	std::cout << std::endl << "Brains: " << std::endl;
	std::cout << "DoG Brain addresses: " << (dzeki.getBrain()) << "---" << dzekiCopy.getBrain() << std::endl;
	std::cout << "CaT Brain addresses: " << (srecko.getBrain()) << "---" << sreckoCopy.getBrain() << std::endl;

	std::cout << std::endl << "Ideas: " << std::endl;
	std::cout << "Original dzeki: " << std::endl << std::endl;
	dzeki.printIdeas();
	std::cout << std::endl;
	std::cout << "Losa kopija dzekija: " << std::endl << std::endl;
	dzekiCopy.printIdeas();
	std::cout << std::endl << "Ideas: " << std::endl;
	std::cout << "Original srecko: " << std::endl << std::endl;
	srecko.printIdeas();
	std::cout << std::endl;
	std::cout << "Losa kopija srecka: " << std::endl << std::endl;
	sreckoCopy.printIdeas();
	std::cout << std::endl;
}
}
