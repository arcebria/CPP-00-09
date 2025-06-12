#include "Dog.hpp"

Dog::Dog(void) {
    type = "Dog";
    std::cout << "The generic animal turned out to be a dog" << std::endl;
}

Dog::~Dog(void) {
    std::cout << "The dog has been destroyed" << std::endl;
}

void    Dog::makeSound(void) const {
    std::cout << "The dog says: Guau guau!!" << std::endl;
}