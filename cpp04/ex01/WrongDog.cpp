#include "WrongDog.hpp"

WrongDog::WrongDog(void) {
    type = "Wrong Dog";
    std::cout << "The wrong animal turned out to be a dog... But is a wrong one" << std::endl;
}

WrongDog::~WrongDog(void) {
    std::cout << "The wrong dog has been destroyed" << std::endl;
}

void    WrongDog::makeSound(void) const {
    std::cout << "The dog says: eeeeeste guau guau..." << std::endl;
}
