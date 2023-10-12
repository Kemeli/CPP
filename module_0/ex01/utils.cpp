#include "PhoneBook.hpp"

void	printContacts(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << str << "|";
}

int	cpp_atoi(std::string str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n);
}
