#include "Karen.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av) {
    Karen devil;

    if (ac < 2) {
        std::cout << "usage: ./Karen-filter [complain]" << std::endl;
        return (-1);
    }
    devil.complain_filter(std::string(av[1]));
    return (0);
}
