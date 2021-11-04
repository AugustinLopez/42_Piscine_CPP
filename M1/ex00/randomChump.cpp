#include "Zombie.hpp"
#include <string>

/**
 * Create a zombie on the stack that announces itself.
 * @param name The zombie name
 */
void randomChump(std::string name) {
    Zombie stack(name);
    stack.annonce();
}
