#include "Animal.hpp"

Animal::Animal(void) : type("Generic Animal") {
    std::cout << "A generic animal has been created" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Generic animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Generic animal assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
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
