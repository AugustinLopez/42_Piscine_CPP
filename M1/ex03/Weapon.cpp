#include "Weapon.hpp"
#include <string>

Weapon::Weapon(void): _type("Nothing") {
    return ;
}

Weapon::Weapon(std::string type): _type(type) {
    return ;
}

Weapon::~Weapon() {
    return ;
}

/**
 * @return a constant reference to the weapon type
 */
std::string const &Weapon::getType(void) const {
    return (this->_type);
}

/**
 *  @param type a new type for the weapon
 */
void Weapon::setType(std::string type) {
    this->_type = type;
}
