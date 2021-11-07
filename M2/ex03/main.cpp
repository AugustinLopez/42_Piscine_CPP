#include "Point.hpp"
#include <iostream>

void print(const Point &A, const Point &B, const Point &C, const Point &P) {
    bool test = bsp(A,B,C,P);

    if (!test) {
        std::cout << "\e[31mNO : \e[0m";
    } else {
        std::cout << "\e[32mYES: \e[0m";
    }
    std::cout << "Dot \e[33m(" << P.getX() << ":" << P.getY() << ") \e[0m";
    if (!test) {
        std::cout << "NOT ";
    }
    std::cout << "in triangle [(" << A.getX() << ":" << A.getY() << "),("
                                  << B.getX() << ":" << B.getY() << "),("
                                  << C.getX() << ":" << C.getY() << ")]" << std::endl;
}

void test_triangle(Point const &A, Point const &B, Point const &C) {
    std::cout << "Test triangle [(" << A.getX() << ":" << A.getY() << "),("
                                  << B.getX() << ":" << B.getY() << "),("
                                  << C.getX() << ":" << C.getY() << ")]" << std::endl;
    std::cout << "Test corner:" << std::endl;
    print(A,B,C,A);
    print(A,B,C,B);
    print(A,B,C,C);

    std::cout << "\nTest corner + UP MIN:" << std::endl;
    print(A,B,C,Point(A.getX().toFloat(), A.getY().toFloat()+FIXED_MIN));
    print(A,B,C,Point(B.getX().toFloat(), B.getY().toFloat()+FIXED_MIN));
    print(A,B,C,Point(C.getX().toFloat(), C.getY().toFloat()+FIXED_MIN));
    std::cout << "\nTest corner + DOWN MIN:" << std::endl;
    print(A,B,C,Point(A.getX().toFloat(), A.getY().toFloat()-FIXED_MIN));
    print(A,B,C,Point(B.getX().toFloat(), B.getY().toFloat()-FIXED_MIN));
    print(A,B,C,Point(C.getX().toFloat(), C.getY().toFloat()-FIXED_MIN));
    std::cout << "\nTest corner + RIGHT MIN:" << std::endl;
    print(A,B,C,Point(A.getX().toFloat()+FIXED_MIN, A.getY().toFloat()));
    print(A,B,C,Point(B.getX().toFloat()+FIXED_MIN, B.getY().toFloat()));
    print(A,B,C,Point(C.getX().toFloat()+FIXED_MIN, C.getY().toFloat()));
    std::cout << "\nTest corner + LEFT MIN:" << std::endl;
    print(A,B,C,Point(A.getX().toFloat()-FIXED_MIN, A.getY().toFloat()));
    print(A,B,C,Point(B.getX().toFloat()-FIXED_MIN, B.getY().toFloat()));
    print(A,B,C,Point(C.getX().toFloat()-FIXED_MIN, C.getY().toFloat()));

    std::cout << "\nTest corner + DOWNLEFT MIN:" << std::endl;
    print(A,B,C,Point(A.getX().toFloat()-FIXED_MIN, A.getY().toFloat()-FIXED_MIN));
    print(A,B,C,Point(B.getX().toFloat()-FIXED_MIN, B.getY().toFloat()-FIXED_MIN));
    print(A,B,C,Point(C.getX().toFloat()-FIXED_MIN, C.getY().toFloat()-FIXED_MIN));
    std::cout << "\nTest corner + DOWNRIGHT MIN:" << std::endl;
    print(A,B,C,Point(A.getX().toFloat()+FIXED_MIN, A.getY().toFloat()-FIXED_MIN));
    print(A,B,C,Point(B.getX().toFloat()+FIXED_MIN, B.getY().toFloat()-FIXED_MIN));
    print(A,B,C,Point(C.getX().toFloat()+FIXED_MIN, C.getY().toFloat()-FIXED_MIN));
    std::cout << "\nTest corner + UPLEFT MIN:" << std::endl;
    print(A,B,C,Point(A.getX().toFloat()-FIXED_MIN, A.getY().toFloat()+FIXED_MIN));
    print(A,B,C,Point(B.getX().toFloat()-FIXED_MIN, B.getY().toFloat()+FIXED_MIN));
    print(A,B,C,Point(C.getX().toFloat()-FIXED_MIN, C.getY().toFloat()+FIXED_MIN));
    std::cout << "\nTest corner + UPRIGHT MIN:" << std::endl;
    print(A,B,C,Point(A.getX().toFloat()+FIXED_MIN, A.getY().toFloat()+FIXED_MIN));
    print(A,B,C,Point(B.getX().toFloat()+FIXED_MIN, B.getY().toFloat()+FIXED_MIN));
    print(A,B,C,Point(C.getX().toFloat()+FIXED_MIN, C.getY().toFloat()+FIXED_MIN));

    std::cout << "\nTest corner + (-0.25:-0.25):" << std::endl;
    print(A,B,C,Point(A.getX().toFloat()-0.25f, A.getY().toFloat()-0.25f));
    print(A,B,C,Point(B.getX().toFloat()-0.25f, B.getY().toFloat()-0.25f));
    print(A,B,C,Point(C.getX().toFloat()-0.25f, C.getY().toFloat()-0.25f));
    std::cout << "\nTest corner + (+0.25:-0.25):" << std::endl;
    print(A,B,C,Point(A.getX().toFloat()+0.25f, A.getY().toFloat()-0.25f));
    print(A,B,C,Point(B.getX().toFloat()+0.25f, B.getY().toFloat()-0.25f));
    print(A,B,C,Point(C.getX().toFloat()+0.25f, C.getY().toFloat()-0.25f));
    std::cout << "\nTest corner + (-0.25:+0.25):" << std::endl;
    print(A,B,C,Point(A.getX().toFloat()-0.25f, A.getY().toFloat()+0.25f));
    print(A,B,C,Point(B.getX().toFloat()-0.25f, B.getY().toFloat()+0.25f));
    print(A,B,C,Point(C.getX().toFloat()-0.25f, C.getY().toFloat()+0.25f));
    std::cout << "\nTest corner + (+0.25:+0.25):" << std::endl;
    print(A,B,C,Point(A.getX().toFloat()+0.25f, A.getY().toFloat()+0.25f));
    print(A,B,C,Point(B.getX().toFloat()+0.25f, B.getY().toFloat()+0.25f));
    print(A,B,C,Point(C.getX().toFloat()+0.25f, C.getY().toFloat()+0.25f));

}


int main(void) {
    test_triangle(Point(10.0f, 0.0f), Point(0.0f,0.0f), Point(0.0f,10.0f));
    std::cout<< "\n" << std::endl;/*

    print(Point(0.0f, 0.0f), Point(0.0f,1.0f), Point(1.0f,0.0f), Point(0.1f, 0.1f)); //OK
    print(Point(0.0f, 0.0f), Point(0.0f,1.0f), Point(1.0f,0.0f), Point(FIXED_MIN, FIXED_MIN));  //OK
    print(Point(0.0f, 0.0f), Point(0.0f,1.0f), Point(1.0f,0.0f), Point(1.0f, 0.0f));  //KO
    print(Point(0.0f, 0.0f), Point(0.0f,-1.0f), Point(-1.0f,0.0f), Point(-0.1f, -0.1f)); //OK
    print(Point(0.0f, 0.0f), Point(0.0f,1.0f), Point(1.0f,0.0f), Point(FIXED_MIN, FIXED_MIN)); //OK
    print(Point(0.0f, 0.0f), Point(0.0f,1.0f), Point(1.0f,0.0f), Point(0.5f, 0.5f)); //OK
    print(Point(0.0f, 0.0f), Point(0.0f,1.0f), Point(1.0f,0.0f), Point(0.6f, 0.6f)); //OK
    print(Point(0.0f, 0.0f), Point(0.0f,1.0f), Point(1.0f,0.0f), Point(0.5f-FIXED_MIN, 0.5f)); //OK
    print(Point(0.0f, 0.0f), Point(0.0f,100.0f), Point(100.0f,0.0f), Point(50.0f-FIXED_MIN, 50.0f)); //OK*/
    return (0);
}
