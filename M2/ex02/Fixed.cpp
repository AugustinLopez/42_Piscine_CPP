#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_lfraction=8;

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

Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs) {
        this->_fix = rhs.getRawBits();
    }
    return *this;
}

Fixed &Fixed::operator++(void) {
    std::cout << "Prefix Increment operator called" << std::endl;
    this->_fix++;
    return *this;
}

Fixed &Fixed::operator--(void) {
    std::cout << "Prefix Decrement operator called" << std::endl;
    this->_fix--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;

    std::cout << "Postfix Increment operator called" << std::endl;
    this->_fix++;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;

    std::cout << "Postfix Decrement operator called" << std::endl;
    this->_fix--;
    return temp;
}

Fixed Fixed::operator+(Fixed const &rhs) const {
    Fixed temp;

    std::cout << "Addition operator called" << std::endl;
    temp.setRawBits(this->getRawBits() + rhs.getRawBits());
    return (temp);
}

Fixed Fixed::operator-(Fixed const &rhs) const {
    Fixed temp;

    std::cout << "Soustraction operator called" << std::endl;
    temp.setRawBits(this->getRawBits() - rhs.getRawBits());
    return (temp);
}

Fixed Fixed::operator*(Fixed const &rhs) const {
    Fixed temp(this->toFloat() * rhs.toFloat());

    std::cout << "Multiplication operator called" << std::endl;
    return (temp);
}

Fixed Fixed::operator/(Fixed const &rhs) const {
    Fixed temp(this->toFloat() / rhs.toFloat());

    std::cout << "Division operator called" << std::endl;
    return (temp);
}

bool Fixed::operator>(Fixed const &rhs) const {
    std::cout << "Greater operator called" << std::endl;
    return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs) const {
    std::cout << "Lesser operator called" << std::endl;
    return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const {
    std::cout << "Greater or equal operator called" << std::endl;
    return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) const {
    std::cout << "Lesser or equal operator called" << std::endl;
    return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs) const {
    std::cout << "Equality operator called" << std::endl;
    return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs) const {
    std::cout << "Inequality operator called" << std::endl;
    return (this->getRawBits() != rhs.getRawBits());
}

int Fixed::getRawBits(void) const {
    return (_fix);
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

const Fixed &Fixed::min(Fixed const &f1, Fixed const &f2) {
    if (f1.getRawBits() <= f2.getRawBits())
        return (f1);
    return (f2);
}

const Fixed &Fixed::max(Fixed const &f1, Fixed const &f2) {
    if (f1.getRawBits() >= f2.getRawBits())
        return (f1);
    return (f2);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
    if (f1.getRawBits() <= f2.getRawBits())
        return (f1);
    return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
    if (f1.getRawBits() >= f2.getRawBits())
        return (f1);
    return (f2);
}
