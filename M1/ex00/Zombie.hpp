#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
    private:
        std::string _name;

    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie();
        void rename(std::string);
        void annonce(void) const;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
