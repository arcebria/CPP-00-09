#include "WrongDog.hpp"

WrongDog::WrongDog(void) {
    type = "Wrong Dog";
    std::cout << "The wrong animal turned out to be a dog... But is a wrong one" << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other) {
    std::cout << "Wrong dog constructor called" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& other) {
    std::cout << "Wrong dog assignment operator called" << std::endl;
    if (this != & other)
        WrongAnimal::operator=(other);
    return *this;
}

WrongDog::~WrongDog(void) {
    std::cout << "The wrong dog has been destroyed" << std::endl;
}

void    WrongDog::makeSound(void) const {
    std::cout << "The dog says: eeeeeste guau guau..." << std::endl;
}
