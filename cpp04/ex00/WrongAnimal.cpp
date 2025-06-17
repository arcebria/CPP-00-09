#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Wrong Animal") {
    std::cout << "A wrong animal has been created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "Wrong animal constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "Wrong animal assignment operator called" << std::endl;
    if (this != & other)
        type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "The wrong animal has been destroyed" << std::endl;
}

void    WrongAnimal::makeSound(void) const {
    std::cout << "The wrong animal makes a wrong sound" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return type;
}
