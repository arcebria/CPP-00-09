#include "Character.hpp"

Character::Character(void) : _name("Unknown") {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "Character default construcor called" << std::endl;
}

Character::Character(std::string const& name) : _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "Character constructor with string called" << std::endl;
}

Character::Character(const Character& other) : _name(other._name) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone(); // creamos una nueva materia, no igualamos los punteros
        else _inventory[i] = NULL;
    }
    std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; i++)
            delete _inventory[i];
        _name = other._name;
        for (int i = 0; i < 4; i++) {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else _inventory[i] = NULL;
        }
    }
    return *this;
}

std::string const& Character::getName(void) const {
    return _name;
}