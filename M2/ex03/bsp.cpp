#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>


bool bsp(Point const a, Point const b, Point const c, Point const Point) {
    double denominator = (b.getY().toFloat() - c.getY().toFloat()) * (a.getX().toFloat() - c.getX().toFloat())
                       + (c.getX().toFloat() - b.getX().toFloat()) * (a.getY().toFloat() - c.getY().toFloat());
    double x = (b.getY().toFloat() - c.getY().toFloat()) * (Point.getX().toFloat() - c.getX().toFloat())
             + (c.getX().toFloat() - b.getX().toFloat()) * (Point.getY().toFloat() - c.getY().toFloat()); 
    double y = (c.getY().toFloat() - a.getY().toFloat()) * (Point.getX().toFloat() - c.getX().toFloat())
             + (a.getX().toFloat() - c.getX().toFloat()) * (Point.getY().toFloat() - c.getY().toFloat());
    x /= denominator;
    y /= denominator;
    double z = 1.0 - x - y;

    return (0.0 < x && x < 1 && 0.0 < y && y < 1 && 0.0 < z && z < 1);
}