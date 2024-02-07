#include "iter.hpp"

int main()
{
	{
		std::cout << "\nint:" << std::endl;
		int arr[] = {1, 2, 3};
		iter<int>(arr, 3, printValue);
	}
	{
		std::cout << "\nfloat:" << std::endl;
		float arr[] = {1.7, 2.156, 3.4};
		iter<float>(arr, 3, printValue);
	}
	{
		std::cout << "\nchar:" << std::endl;
		char arr[] = {'a', 'b', 'c'};
		iter<char>(arr, 3, printValue);
	}
	{
		std::cout << "\nstring:" << std::endl;
		std::string arr[] = {"abc", "def", "ghi"};
		iter<std::string>(arr, 3, printValue);
	}
	{
		std::cout << "\nbool:" << std::endl;
		bool arr[] = {true, true, false};
		iter<bool>(arr, 3, printValue);
	}
}
