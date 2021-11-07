#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(Weapon &weapon): _weapon(weapon),  _name("") {
    return ;
}

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon),  _name(name) {
    return ;
}

HumanA::~HumanA(void) {
    return ;
}

/**
 * @param name a new name for the human.
 */
void HumanA::rename(std::string name) {
    this->_name = name;
}

/**
 * @param weapon a new weapon type.
 */
void HumanA::setWeapon(std::string type) {
    this->_weapon.setType(type);
}

/**
 * print "NAME attack with his WEAPON_TYPE" on stdout.
 */
void HumanA::attack(void) const {
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
