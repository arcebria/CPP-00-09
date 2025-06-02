#include "Zombie.hpp"

int main(void) {
    int n = 4;
    Zombie* zombie = zombieHorde(n, "Arnau");
    for (int i = 0; i < n; i++) 
        zombie[i].announce();
    delete[] zombie;
    return 0;
}