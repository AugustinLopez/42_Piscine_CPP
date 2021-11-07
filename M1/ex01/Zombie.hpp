#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
    private:
        std::string _name;

    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);
        void rename(std::string);
        void annonce(void) const;
};

Zombie *ZombieHorde(int N, std::string name);

#endif
