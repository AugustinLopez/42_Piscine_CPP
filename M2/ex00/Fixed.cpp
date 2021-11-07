#include "Fixed.hpp"
#include <iostream>

const int Fixed::_lfraction=8;

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_fix);
}

Fixed::Fixed(void): _fix(0) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(Fixed const &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
    return ;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed &Fixed::operator=(Fixed const &equal) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &equal) {
        this->_fix = equal.getRawBits();
    }
    return *this;
}

void Fixed::setRawBits(int const raw) {
    this->_fix = raw;
}
