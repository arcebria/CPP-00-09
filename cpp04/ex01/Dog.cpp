#include "Dog.hpp"

Dog::Dog(void) {
    type = "Dog";
    std::cout << "The generic animal turned out to be a dog" << std::endl;
    dogBrain = new Brain();
}

Dog::~Dog(void) {
    delete dogBrain;
    std::cout << "The dog has been destroyed" << std::endl;
}

void    Dog::makeSound(void) const {
    std::cout << "The dog says: Guau guau!!" << std::endl;
}
