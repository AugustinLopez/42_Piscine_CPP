#include "Fixed.hpp"
#include <iostream>

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed const c(Fixed(5.05f) / Fixed(2));
    Fixed const d(Fixed(5.05f) + Fixed(2));
    Fixed const e(Fixed(5.05f) - Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "\n\nMyOwnTest:\n" << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;
    std::cout << --a << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << (a != b) << std::endl;
    std::cout << (a != a) << std::endl;
    std::cout << (a < b) << std::endl;
    std::cout << (a < a) << std::endl;
    std::cout << (a <= a) << std::endl;
    return (0);
}
