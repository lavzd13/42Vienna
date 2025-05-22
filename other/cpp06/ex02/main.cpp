#include "Base.hpp"

int	main(void) {
	Base test;

	Base* aaa = test.generate();
	Base* bbb = test.generate();
	Base* ccc = test.generate();

	test.identify(aaa);
	test.identify(bbb);
	test.identify(ccc);

	Base& eeey = *aaa;
	Base& sitdown = *bbb;
	Base& listen = *ccc;

	test.identify(eeey);
	test.identify(sitdown);
	test.identify(listen);

	delete aaa;
	delete bbb;
	delete ccc;
}