#include "Fixed.hpp"
#include "Point.hpp"

Fixed const &Point::getX(void) const {
    if (this->_assigned)
        return (this->_myX);
    return (this->_x);
}

Fixed const &Point::getY(void) const {
    if (this->_assigned)
        return (this->_myY);
    return (this->_y);
}

Point::~Point(void) {
    return ;
}

Point::Point(void): _x(Fixed(0)), _y(Fixed(0)), _myX(Fixed(0)), _myY(Fixed(0)), _assigned(false) {
    return;
}

Point::Point(Point const &copy): _x(copy.getX()), _y(copy.getY()), _myX(copy.getX()), _myY(copy.getY()), _assigned(false) {
    return;
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)), _myX(Fixed(x)), _myY(Fixed(y)), _assigned(false) {
    return;
}

Point &Point::operator=(Point const &rhs) {
    if (this != &rhs) {
        this->_assigned = true;
        this->_myX.setRawBits(rhs.getX().getRawBits());
        this->_myY.setRawBits(rhs.getY().getRawBits());
    }
    return *this;
}