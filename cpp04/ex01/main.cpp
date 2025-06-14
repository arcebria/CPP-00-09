#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main(void) {
    const   Animal* doggy = new Dog();
    const   Animal* cat   = new Cat();

    delete  doggy;
    delete  cat;
    return 0;
}
