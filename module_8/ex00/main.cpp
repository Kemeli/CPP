#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << "\n------TEST WITH VECTOR------" << std::endl;
	std::vector<int> vec;

	vec.push_back(22);
	vec.push_back(11);
	vec.push_back(33);
	vec.push_back(44);
	vec.push_back(55);
	vec.push_back(66);

	try
	{
		unsigned int index = easyfind(vec, 22);
		std::cout << "Value found in position " << index << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n------TEST WITH LIST------" << std::endl;
	std::list<int> lst;

	lst.push_back(22);
	lst.push_back(11);
	lst.push_back(33);
	lst.push_back(44);
	lst.push_front(55);
	lst.push_front(66);

	try
	{
		unsigned int index = easyfind(lst, 22);
		std::cout << "Value found in position " << index << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\n------TEST WITH DEQUE------" << std::endl;
	std::deque<int> deq;

	deq.push_back(22);
	deq.push_back(11);
	deq.push_back(33);
	deq.push_back(44);
	deq.push_front(55);
	deq.push_front(66);

	try
	{
		unsigned int index = easyfind(deq, 22);
		std::cout << "Value found in position " << index << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}
