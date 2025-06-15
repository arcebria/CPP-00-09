#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main(void) {
    // int arraySize = 6;
    // Animal*  animals[arraySize];

    // std::cout << "[CREATING ANIMALS]\n" << std::endl;

    // int i = 0;
    // while (i < arraySize / 2)
    //     animals[i++] = new Dog();
    // i = arraySize / 2;
    // while (i < arraySize)
    //     animals[i++] = new Cat();

    // std::cout << "\n[MAKING NOISES]\n" << std::endl;

    // i = 0;
    // while (i < arraySize) {
    //     std::cout   << animals[i]->getType() << " says: ";
    //     animals[i]->makeSound();
    //     i++;
    // }

    // std::cout << "\n[DELETING ANIMALS]\n" << std::endl;

    // i = 0;
    // while (i < arraySize)
    //     delete animals[i++];
    
    std::cout << "\n[TESTING DEEP COPY]\n" << std::endl;

    Dog originalDog;
    {
        Dog dogCopy(originalDog); // constructor de copia
        std::cout << "Both dogs exists" << std::endl;
    }// al crear la copia dentro de los braqutes esta se destruye automaticamente al final del scope y no al final del programa
    std::cout << "COPY DESTROYED... ORIGINAL ALIVE TILL THE END OF THE PROGRAM\n" << std::endl;

    Cat originalCat;
    Cat anotherCat;
    std::cout << "\nAssignment stuff starting\n" << std::endl;
    anotherCat = originalCat; // operador de asignacion
    std::cout << "\nAssignments stuff ending\n" << std::endl;
    return 0;
}
