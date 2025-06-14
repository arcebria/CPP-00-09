#include "Cat.hpp"

Cat::Cat(void) {
    type = "Cat";
    std::cout << "The generic animal turned out to be a cat" << std::endl;
    catBrain =  new Brain();
}

Cat::~Cat(void) {
    delete catBrain;
    std::cout << "The cat has been destroyed" << std::endl;
}

void    Cat::makeSound(void) const {
    std::cout << "The cat says: Miau miau" << std::endl;
}
