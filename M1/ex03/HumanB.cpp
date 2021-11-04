#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(void): _weapon(NULL), _name("") {
  return ;
}

HumanB::HumanB(std::string name): _weapon(NULL), _name(name) {
  return ;
}

HumanB::~HumanB() {
  return ;
}

/**
 * @param name a new name for the human.
 */
void HumanB::rename(std::string name) {
  this->_name = name;
}

/**
 * @param weapon a new weapon.
 */
void HumanB::setWeapon(Weapon &weapon) {
  this->_weapon = &weapon;
}

/**
 * print "NAME attack with his WEAPON_TYPE" on stdout.
 */
void HumanB::attack(void) const {
  if (this->_weapon != NULL)
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
  else
    std::cout << this->_name << " tries to attack but he has no weapon" << std::endl;
}
