#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
    private:
        Weapon &_weapon;
        std::string _name;
    
    public:
        HumanA(Weapon &weapon);
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void rename(std::string name);
        void setWeapon(std::string type);
        void attack(void) const;
};

#endif
