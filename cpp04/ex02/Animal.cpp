#include "Animal.hpp"

AAnimal::AAnimal(void) : type("Generic AAnimal") {
    std::cout << "A generic animal has been created" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "AAnimal copy called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "AAnimal operator assignment called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

AAnimal::~AAnimal(void) {
    std::cout << "The generic animal has been destroyed" << std::endl;
}

// void    AAnimal::makeSound(void) const {
//     std::cout << "The generic animal makes a generic sound" << std::endl;
// }

std::string AAnimal::getType(void) const {
    return type;
}