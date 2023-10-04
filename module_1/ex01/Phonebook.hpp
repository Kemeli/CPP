#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

class PhoneBook
{
	private:
	Contact contacts_list[8];

	public:
	PhoneBook();
	void addContact(Contact c);
	int	last_contact;
};

#endif
