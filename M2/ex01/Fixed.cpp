#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_lfraction=8;

int Fixed::getRawBits(void) const {
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

Fixed::Fixed(const int val): _fix(val << 8) {
    std::cout << "Int constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const float val): _fix(roundf((val * (1 << 8)))) {
    std::cout << "Float constructor called" << std::endl;
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

float Fixed::toFloat(void) const {
    return ((float)((1.0 * _fix) / (1 << 8)));
}

int Fixed::toInt(void) const {
    return (_fix / (1 << 8));
}

std::ostream &operator<<(std::ostream &stream, Fixed const &val) {
    if (val.getRawBits() && 0xffff == 0)
        stream << val.toInt();
    else
        stream << val.toFloat();
    return (stream);
}
