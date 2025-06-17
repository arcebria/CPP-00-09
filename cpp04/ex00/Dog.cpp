#include "Dog.hpp"

Dog::Dog(void) {
    type = "Dog";
    std::cout << "The generic animal turned out to be a dog" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog(void) {
    std::cout << "The dog has been destroyed" << std::endl;
}

void    Dog::makeSound(void) const {
    std::cout << "The dog says: Guau guau!!" << std::endl;
}
