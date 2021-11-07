#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_lfraction=8;

Fixed::Fixed(void): _fix(0) {
    return ;
}

Fixed::Fixed(Fixed const &copy) {
    *this = copy;
    return ;
}

Fixed::Fixed(const int val): _fix(val << 8) {
    return ;
}

Fixed::Fixed(const float val): _fix(roundf((val * (1 << 8)))) {
    return ;
}

Fixed::~Fixed(void) {
    return ;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    if (this != &rhs) {
        this->_fix = rhs.getRawBits();
    }
    return *this;
}

Fixed &Fixed::operator++(void) {
    this->_fix++;
    return *this;
}

Fixed &Fixed::operator--(void) {
    this->_fix--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;

    this->_fix++;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;

    this->_fix--;
    return temp;
}

Fixed Fixed::operator+(Fixed const &rhs) const {
    Fixed temp;

    temp.setRawBits(this->getRawBits() + rhs.getRawBits());
    return (temp);
}

Fixed Fixed::operator-(Fixed const &rhs) const {
    Fixed temp;

    temp.setRawBits(this->getRawBits() - rhs.getRawBits());
    return (temp);
}

Fixed Fixed::operator*(Fixed const &rhs) const {
    Fixed temp(this->toFloat() * rhs.toFloat());

    return (temp);
}

Fixed Fixed::operator/(Fixed const &rhs) const {
    Fixed temp(this->toFloat() / rhs.toFloat());

    return (temp);
}

bool Fixed::operator>(Fixed const &rhs) const {
    return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs) const {
    return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const {
    return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) const {
    return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs) const {
    return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs) const {
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
