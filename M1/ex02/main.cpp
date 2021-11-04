#include <iostream>
#include <string>

int main(void) {
    std::string Pinky = "HI THIS IS BRAIN";
    std::string *stringPTR = &Pinky;
    std::string &stringREF = Pinky;

    std::cout << "\nString address:    " << &Pinky
              << "\nstringPTR address: " << stringPTR
              << "\nstringREF address: " << &stringREF
              << "\nstringPTR value:   " << *stringPTR
              << "\nstringREF value:   " << stringREF << std::endl;
    return (0);
}
