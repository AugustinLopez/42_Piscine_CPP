#include "Zombie.hpp"
#include <string>
#include <sstream>

/**
 * Create a horde of N Zombie.
 * @param name the name of each zombie: a numero is added to differentiate between them.
 * @return a pointer to the Zombie horde.
 */
Zombie *ZombieHorde(int N, std::string name)
{
    Zombie *Horde = new Zombie[N];
    std::ostringstream ss;

    for (int i = 0; i < N; i++) {
        ss.str("");
        ss.clear();
        ss << i + 1;
        Horde[i].rename(name + " " + ss.str());
    }
    return (Horde);
}
