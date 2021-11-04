#include "Karen.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av) {
    Karen devil;

    if (ac < 2) {
        std::cout << "usage: ./Karen [complain1, complain2, ...]" << std::endl;
        return (-1);
    }
    for (int i = 1; i < ac; i++) {
        std::cout << i << "-" << av[i] << ": ";
        devil.complain(std::string(av[i]));
        std::cout << std::endl;
    }
    return (0);
}
