#include "class.phonebook.hpp"
#include <iostream>
#include <string>

/**
 * Procedure to ADD, SEARCH or EXIT a mini-phonebook with 8 entries.
 */
int main(void) {
    std::string input;
    Phonebook annuaire;
    
    std::cout << "--- PROGRAM START ---" << std::endl;
    while (std::cin.eof() == false) {
        std::cout << ">> ";
        std::getline(std::cin, input);
        if (input.compare("ADD") == 0)
            annuaire.add();
        else if (input.compare("SEARCH") == 0)
            annuaire.search();
        else if (input.compare("EXIT") == 0)
            break ;
        else if (input.compare("") != 0)
            std::cerr << "Unknown command" << std::endl;
        input.clear();
    }
    return (0);
}
