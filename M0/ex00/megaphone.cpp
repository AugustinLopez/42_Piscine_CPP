#include <iostream>

/**
 * Translate lowercase ASCII from argv into uppercase ASCII. Print the result on stdout.
 * If not enough argument are provided, print a default string.
**/
int main(int ac, char **av) {
    if (ac < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < ac; i++) {
        for (char *ptr = av[i]; *ptr != '\0'; ptr++)
            *ptr += (*ptr >= 'a' && *ptr <= 'z') * ('A' + 'a');
        std::cout << av[i];
    }
    std::cout << std::endl;
    return (0);
}
