#include "class.phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

Phonebook::Phonebook(void) : _count(0) {
	return ;
}

Phonebook::~Phonebook(void) {
	return ;
}

/**
 * Procedure to add a contact in the phone book.
 * @return -1 if the contact limit is reached, 0 otherwise
 */
int	Phonebook::add(void) {
	if (this->_count >= 8) {
		std::cerr << "Error: Contact limit reached for this phonebook" << std::endl;
        return (-1);
    }
	(this->_entry)[this->_count].add_from_io();
	(this->_count)++;
	return (0);
}

/**
 *  Procedure to display a summary of all contact in the phonebook.
 */
void	Phonebook::_display_all(void) const {
	for (unsigned int i = 0; i < this->_count; i++) {
		(this->_entry)[i].summary(i + 1);
	}
}

/**
 * Procedure to display the info from the contact at index i
 * @param i index of the contact in the phonebook
 * @return -1 if the index does not exists, 0 otherwise
 */
int	Phonebook::_display_one(unsigned int i) const {
	if (i <= 0 || i > this->_count) {
		std::cerr << "Error: invalid index" << std::endl;
        return (-1);
    }
	(this->_entry)[i - 1].info();
    return (0);
}

/**
 * Procedure that display a summary of the phone book info, ask for an index, an print its information. 
 * This procedure use I/O operations.
 * @return -1 if an error is encountered, 0 otherwise.
 */
int Phonebook::search(void) const {
    std::string input;
    unsigned long index;

    this->_display_all();
    std::cout << "(Enter Index) >> ";
    std::getline(std::cin, input);
    if (input.compare("") == 0) {
        std::cout << std::endl;
        return (0);
    }
    try {
        index = strtoul(input.c_str(), NULL, 10);
    } catch (...) {
        std::cerr << "Error: could not parse a valid index from input" << std::endl;
        return (-1);
    }
    return (this->_display_one(index));
}
