#include "Character.hpp"

Character::Character(void) : _name("Unknown") {
    std::cout << "Character default construcor called" << std::endl;
}

Character::Character(std::string const& name) : _name(name) {
    std::cout << "Character constructor with string called" << std::endl;
}