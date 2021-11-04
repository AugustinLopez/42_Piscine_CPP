#include "Zombie.hpp"
#include <string>

/**
 *  Create a Zombie on the heap
 * @param name The Zombie name
 * @return the Zombie
 */
Zombie* newZombie(std::string name) {
    Zombie *heap = new Zombie(name);
    return (heap);
}
