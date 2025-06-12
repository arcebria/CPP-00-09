#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
    const   Animal* animal = new Animal();
    const   Animal* doggy = new Dog();
    const   Animal* cat = new Cat();

    std::cout   <<  "Doggy type is: " << doggy->getType() << std::endl
                <<  "Cat type is: " << cat->getType() << std::endl;
    animal->makeSound();
    doggy->makeSound();
    cat->makeSound();
    delete animal;
    delete doggy;
    delete cat;
}