#include "Animal.hpp"

Animal::Animal(void) : type("Generic Animal") {
    std::cout << "A generic animal has been created" << std::endl;
}

Animal::~Animal(void) {
    std::cout << "The generic animal has been destroyed" << std::endl;
}

void    Animal::makeSound(void) const {
    std::cout << "The generic animal makes a generic sound" << std::endl;
}

std::string Animal::getType(void) const {
    return type;
}