#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        Fixed const _x;
        Fixed const _y;
        Fixed _myX;
        Fixed _myY;
        bool _assigned;

    public:
        Point(void);
        Point(Point const &copy);
        Point(float const x, float const y);
        Point &operator=(Point const &rhs);
        ~Point(void);
        Fixed const &getX(void) const;
        Fixed const &getY(void) const;

};

bool bsp(Point const a, Point const b, Point const c, Point const Point);

#endif