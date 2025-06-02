#include "Zombie.hpp"

void    Zombie::setName(std::string zombieName) {
    name = zombieName;
}

// para crear un array de objetos new Zombie[n] se debe llamar a un construcotr por defecto
// por eso en este ejercicio quitamos el name del constructor y lo añadimos despues con setName
Zombie* zombieHorde(int n, std::string name) {
    Zombie *zombie = new Zombie[n];
    for (int i = 0; i < n; i++)
        zombie[i].setName(name);
    return(zombie);
}