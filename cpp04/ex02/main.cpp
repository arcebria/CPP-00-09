#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main(void) {
    //virtual void makeSound() const = 0; --> esto es una funcion virtual pura
    //quiere decir que solo puede ser usada por las clases hijas
    //si una clase tiene al menos uno de sus metodos con esta sintaxis quiere decir que es una clase abstracta
    //y no se puede instanciar un objecto de clase abstracta
    //AAnimal *animal = new AAnimal();
    const AAnimal* doggy = new Dog();
    doggy->makeSound();
    delete  doggy;
    return 0;
}
