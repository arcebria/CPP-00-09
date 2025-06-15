#include "Cat.hpp"

Cat::Cat(void) {
    type = "Cat";
    std::cout << "The generic animal turned out to be a cat" << std::endl;
    catBrain =  new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    std::cout << "Cat copy called" << std::endl;
    catBrain = new Brain(*other.catBrain);
}

Cat& Cat::operator=(const Cat& other){
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        delete catBrain;
        catBrain = new Brain(*other.catBrain);
    }
    return *this;
}

Cat::~Cat(void) {
    delete catBrain;
    std::cout << "The cat has been destroyed" << std::endl;
}

void    Cat::makeSound(void) const {
    std::cout << "The cat says: Miau miau" << std::endl;
}
