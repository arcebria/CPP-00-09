#include "WrongCat.hpp"

WrongCat::WrongCat (void) {
    type = "Wrong Cat";
    std::cout << "The wrong animal turned out to be a cat... But is a wrong one" << std::endl;
}

WrongCat::~WrongCat(void) {
    std::cout << "The wrong cat has been destroyed" << std::endl;
}

void    WrongCat::makeSound(void) const {
    std::cout << "The wrong cat says: mimimimimimimimimi" << std::endl;
}
