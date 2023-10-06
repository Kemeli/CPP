#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook
{
	private:
	Contact contacts_list[8]; //7?
	int	index;

	public:
	PhoneBook();
	void addContact(Contact c);
	void displayContacts();
	void search(PhoneBook &agenda);
};

#endif
