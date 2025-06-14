#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

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

    std::cout << std::endl;
    //-------------------------------
    const   WrongAnimal* noAnimal = new WrongAnimal();
    const   WrongAnimal* noDoggy = new WrongDog();
    const   WrongAnimal* noCat = new WrongCat();
    std::cout   <<  "NoDoggy type is: " << noDoggy->getType() << std::endl
                <<  "NoCat type is: " << noCat->getType() << std::endl;
    noAnimal->makeSound();
    noDoggy->makeSound();
    noCat->makeSound();
    delete noAnimal;
    delete noDoggy;
    delete noCat;

    return 0;
}
