#ifndef CLASS_PHONEBOOK_HPP
# define CLASS_PHONEBOOK_HPP

#include "class.contact.hpp"

class Phonebook
{
	private:
		Contact	_entry[8];
		unsigned int _count;
        void _display_all(void) const;
		int _display_one(unsigned int) const;

	public:
		Phonebook(void);
		~Phonebook(void);
		int add(void);
        int search(void) const;
};

#endif
