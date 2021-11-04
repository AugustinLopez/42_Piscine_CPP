#include "Zombie.hpp"

int main(void) {
    int N = 10;

    Zombie *Horde = ZombieHorde(N, "Extra");

    for (int i = 0; i < N; i++)
        Horde[i].annonce();
    delete [] Horde;
    return (0);
}
