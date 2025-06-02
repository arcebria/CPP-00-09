#include "Zombie.hpp"

int main(void) {
    randomChump("Guillem");

    std::cout << "-----------------------" << std::endl;

    Zombie* zombie1 = newZombie("Arnau");
    zombie1->announce();
    delete(zombie1);
    return 0;
}