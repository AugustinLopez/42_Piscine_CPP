#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
    private:
        Weapon *_weapon;
        std::string _name;
    
    public:
        HumanB(void);
        HumanB(std::string name);
        ~HumanB(void);
        void rename(std::string name);
        void setWeapon(Weapon &weapon);
        void attack(void) const;
};

#endif
