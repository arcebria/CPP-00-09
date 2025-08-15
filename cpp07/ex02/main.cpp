#include "Array.hpp"

int main() {
    Array<int> empty;
    std::cout << "Size del array vacio = " << empty.size() << std::endl;
    try {
        std::cout << "Intentando acceder a algun valor del array" << std::endl;
        std::cout << empty[1] << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Excecpcion capturada: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    

    Array<int> numbers(5);
    Array<std::string> strings(3);

    std::cout << "--LLenando arrays--\n" << std::endl;
    

    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = (i + 1) * 10;
        std::cout << "Numbers[" << i << "] = " << numbers[i] << std::endl; 
    }
    std::cout << std::endl;

    strings[0] = "Hello, ";
    strings[1] = "World";
    strings[2] = "!";

    for (unsigned int i = 0; i < strings.size(); i++) {
        std::cout << strings[i];
    }
    std::cout << std::endl;
    std::cout << std::endl;

    Array<int> copy(numbers);
    std::cout << "Tamaño del original: " << numbers.size() << std::endl;
    std::cout << "Tamaño de la copia: " << copy.size() << std::endl;

    numbers[0] = 0;
    std::cout << "Posicion 0 original modificada: " << numbers[0] << std::endl;
    std::cout << "Posicion 0 de la copia no modificada: " << copy[0] << std::endl;
    std::cout << std::endl;

    Array<int> assigned(2);
    assigned = numbers;
    std::cout << "Tamaño del original: " << numbers.size() << std::endl;
    std::cout << "Tamaño de la asignacion: " << assigned.size() << std::endl;

    numbers[1] = 0;
    std::cout << "Posicion 1 original modificada: " << numbers[1] << std::endl;
    std::cout << "Posicion 0 de la asignacion no modificada: " << assigned[1] << std::endl;
   
    return 0;
}