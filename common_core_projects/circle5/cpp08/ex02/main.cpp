#include "MutantStack.hpp"
#include <list>

/* int	main(void) {
	MutantStack<int>	stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
} */

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	const MutantStack<int>	copy(mstack);
	std::cout << std::endl;
	MutantStack<int>::const_iterator cit = mstack.begin();
	MutantStack<int>::const_iterator cite = mstack.end();
	++cit;
	--cit;
	while (cit != cite)
	{
	std::cout << *cit << std::endl;
	++cit;
	}

	std::cout << "--------------------------------------------------------------------------" << std::endl;

	std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    //[...]
    mlist.push_back(0);

    std::list<int>::iterator itl = mlist.begin();
    std::list<int>::iterator itel = mlist.end();
    ++itl;
    --itl;
    while (itl != itel)
    {
        std::cout << *itl << std::endl;
        ++itl;
    }

    std::list<int> sl(mlist);
	return 0;
}