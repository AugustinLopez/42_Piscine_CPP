#include "class.contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>


Contact::Contact(void): _initialized(false) {
    return ;
}

Contact::~Contact(void) {
    return ;
}

/**
 * Procedure to add/overwrite a Contact detail from I/O operations.
 */
void Contact::add_from_io(void) {
    int i = 0;

	std::cout << "First name please: ";
	std::getline(std::cin, (this->_elem)[i++]);
	std::cout << "Last name please: ";
	std::getline(std::cin, (this->_elem)[i++]);
	std::cout << "nickname please: ";
	std::getline(std::cin, (this->_elem)[i++]);
	std::cout << "login please: ";
	std::getline(std::cin, (this->_elem)[i++]);
	std::cout << "Postal address please: ";
	std::getline(std::cin, (this->_elem)[i++]);
	std::cout << "Email address please: ";
	std::getline(std::cin, (this->_elem)[i++]);
	std::cout << "Phone number please: ";
	std::getline(std::cin, (this->_elem)[i++]);
	std::cout << "Birthday date please: ";
	std::getline(std::cin, (this->_elem)[i++]);
	std::cout << "Favorite meal please: ";
	std::getline(std::cin, (this->_elem)[i++]);
	std::cout << "Underwear color please: ";
	std::getline(std::cin, (this->_elem)[i++]);
	std::cout << "Darkest secret please: ";
	std::getline(std::cin, (this->_elem)[i++]);
	std::cout << "--- CONTACT INITIALIZED ---" << std::endl;
	this->_initialized = true;
}

/**
 * Print up to 10 characters from a element
 */
void	Contact::_elem_summary(_index i) const
{
	if ((this->_elem)[i].size() > 9)
		std::cout << (this->_elem)[i].substr(0,9) << '.';
	else
		std::cout << std::setw(10) << std::right << (this->_elem)[i];
}

/**
 * Procedure that write the First Name, Last Name, and Login on stdout. Up to 10 characters are printed.
 * Format: Index ... | First ... |Last ... |Login ...
 * If any element is too short, space characters are added. 
 * If any element is too long, the 10th character is replaced by a dot.
 * 
 * @param index If -1, no index is printed. The value printed as index otherwise.
 */
void	Contact::summary(int index = -1) const
{
    if (index > -1) {
        std::cout << std::setw(10) << std::right << index;
    	std::cout << '|';
    }
	this->_elem_summary(FIRST_NAME);
	std::cout << '|';
	this->_elem_summary(LAST_NAME);
	std::cout << '|';
	this->_elem_summary(LOGIN);
	std::cout << std::endl;
}

/**
 * Procedure that write the First Name, Last Name, Postal Address, Email Address and Phone number of the contact
 */
void	Contact::info(void) const
{
	std::cout << (this->_elem)[FIRST_NAME] << std::endl;
	std::cout << (this->_elem)[LAST_NAME] << std::endl;
	std::cout << (this->_elem)[POSTAL_ADDRESS] << std::endl;
	std::cout << (this->_elem)[EMAIL_ADDRESS] << std::endl;
	std::cout << (this->_elem)[PHONE_NUMBER] << std::endl;
}