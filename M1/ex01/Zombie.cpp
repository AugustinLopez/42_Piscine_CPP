#include "Zombie.hpp"
#include <string>
#include <iostream>

/**
 * Constructor.
 */
Zombie::Zombie(void): _name("") {
    return ;
}

Zombie::Zombie(std::string name): _name(name) {
    return ;
}

/**
 * Destructor. Destruction message is printed on stdout to respect subject requirement.
 */
Zombie::~Zombie() {
    std::cout << "<" + this->_name + "> has been fired !" << std::endl;
}

/**
 * The zombie announces its name and its favorite food.
 */
void Zombie::annonce(void) const {
    std::cout << "<" + this->_name + "> BraiiiiiiinnnzzzZ..." << std::endl;
}

/**
 *  The zombie get a new name.
 */
void Zombie::rename(std::string name) {
    this->_name = name;
}
