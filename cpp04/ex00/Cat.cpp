#include "Cat.hpp"

Cat::Cat(void) {
    type = "Cat";
    std::cout << "The generic Cat turned out to be a cat" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat(void) {
    std::cout << "The cat has been destroyed" << std::endl;
}

void    Cat::makeSound(void) const {
    std::cout << "The cat says: Miau miau" << std::endl;
}
