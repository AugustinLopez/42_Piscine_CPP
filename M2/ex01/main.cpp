#include "Fixed.hpp"
#include <iostream>
#include <climits>

void another_test(void){
    std::cout << "First another test:" << std::endl;

    Fixed a;
    a.setRawBits(INT_MAX);
    std::cout << "a is " << a << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    a.setRawBits(INT_MIN);
    std::cout << "a is " << a << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    a.setRawBits(1);
    std::cout << "a is " << a << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    a.setRawBits(-1);
    std::cout << "a is " << a << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
}

int main(void) {
    another_test();
    std::cout << "\n\n" << std::endl;
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return (0);
}
