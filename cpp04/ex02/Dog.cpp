#include "Dog.hpp"

Dog::Dog(void) {
    type = "Dog";
    std::cout << "The generic animal turned out to be a dog" << std::endl;
    dogBrain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    std::cout << "Dog copy called" << std::endl;
    dogBrain = new Brain(*other.dogBrain);
}

Dog& Dog::operator=(const Dog& other){
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        delete dogBrain;
        dogBrain = new Brain(*other.dogBrain);
    }
    return *this;
}

Dog::~Dog(void) {
    delete dogBrain;
    std::cout << "The dog has been destroyed" << std::endl;
}

void    Dog::makeSound(void) const {
    std::cout << "The dog says: Guau guau!!" << std::endl;
}
