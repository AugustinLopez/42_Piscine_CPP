#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
    private:
        std::string _type;

    public:

        Weapon(void);
        Weapon(std::string type);
        ~Weapon();
        std::string const &getType(void) const;
        void setType(std::string type);
};

#endif
