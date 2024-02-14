#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << PINK << "\n------SUBJECT TEST------" << RESET << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "size: " << mstack.size() << std::endl;

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
			std::cout << *it << ((*it != *ite) ? ", " : "\n");
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}

	{
		std::cout << PINK << "\n------MSTACK VS LIST------" << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(23);
		mstack.push(43);
		mstack.push(65);
		mstack.push(87);
		mstack.push(90);
		mstack.push(98);

		std::list<int> lst;
		lst.push_back(23);
		lst.push_back(43);
		lst.push_back(65);
		lst.push_back(87);
		lst.push_back(90);
		lst.push_back(98);

		std::cout << BLUE << "mstack:" << RESET << std::endl;
		MutantStack<int>::iterator it1 = mstack.begin();
		MutantStack<int>::iterator ite1 = mstack.end();
		while(it1 != ite1)
			std::cout << *it1 << ((++it1 != ite1) ? ", " : "\n");

		std::cout << BLUE << "lst:" << RESET << std::endl;
		std::list<int>::iterator it2 = lst.begin();
		std::list<int>::iterator ite2 = lst.end();
		while(it2 != ite2)
			std::cout << *it2 << ((++it2 != ite2) ? ", " : "\n");

		std::cout << BLUE << "mstack size:" << RESET << std::endl;
		std::cout << mstack.size() << std::endl;

		std::cout << BLUE << "lst size:" << RESET << std::endl;
		std::cout << lst.size() << std::endl;

		std::cout << std::endl;
	}

	{
		std::cout << PINK << "\n------ASSIGNMENT OPERATOR TEST------" << RESET << std::endl;
		MutantStack<int> mstack;
		MutantStack<int> mstack2;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		mstack2 = mstack;

		std::cout << BLUE << "original stack:" << RESET << std::endl;
		MutantStack<int>::iterator it1 = mstack.begin();
		MutantStack<int>::iterator ite1 = mstack.end();
		while(it1 != ite1)
			std::cout << *it1 << ((++it1 != ite1) ? ", " : "\n");

		std::cout << BLUE << "copy stack:" << RESET << std::endl;
		MutantStack<int>::iterator it2 = mstack2.begin();
		MutantStack<int>::iterator ite2 = mstack2.end();
		while(it2 != ite2)
			std::cout << *it2 << ((++it2 != ite2) ? ", " : "\n");
		std::cout << std::endl;


		std::cout << BLUE << "original stack after push:" << RESET << std::endl;
		mstack.push(42);
		it1 = mstack.begin();
		ite1 = mstack.end();
		while(it1 != ite1)
			std::cout << *it1 << ((++it1 != ite1) ? ", " : "\n");

		std::cout << BLUE << "copy stack after push on original stack:" << RESET << std::endl;
		it2 = mstack2.begin();
		ite2 = mstack2.end();
		while(it2 != ite2)
			std::cout << *it2 << ((++it2 != ite2) ? ", " : "\n");
		std::cout << std::endl;
	}

	{
		std::cout << PINK << "\n------COPY CONSTRUCTOR TEST------" << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(10);
		mstack.push(29);
		mstack.push(38);
		mstack.push(47);
		mstack.push(56);
		mstack.push(91);
		mstack.push(82);
		mstack.push(73);

		std::cout << BLUE << "original stack:" << RESET << std::endl;
		MutantStack<int>::iterator it1 = mstack.begin();
		MutantStack<int>::iterator ite1 = mstack.end();
		while(it1 != ite1)
			std::cout << *it1 << ((++it1 != ite1) ? ", " : "\n");

		std::cout << BLUE << "copy stack:" << RESET << std::endl;
		MutantStack<int> mstack2(mstack);
		MutantStack<int>::iterator it2 = mstack2.begin();
		MutantStack<int>::iterator ite2 = mstack2.end();
		while(it2 != ite2)
			std::cout << *it2 << ((++it2 != ite2) ? ", " : "\n");
		std::cout << std::endl;

		std::cout << BLUE << "original stack after push:" << RESET << std::endl;
		mstack.push(42);
		it1 = mstack.begin();
		ite1 = mstack.end();
		while(it1 != ite1)
			std::cout << *it1 << ((++it1 != ite1) ? ", " : "\n");

		std::cout << BLUE << "copy stack after push on original stack:" << RESET << std::endl;
		it2 = mstack2.begin();
		ite2 = mstack2.end();
		while(it2 != ite2)
			std::cout << *it2 << ((++it2 != ite2) ? ", " : "\n");

		std::cout << std::endl;
	}

	return 0;
}
