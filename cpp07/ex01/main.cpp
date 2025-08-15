#include "iter.hpp"

//funcion implementada con template (Function template)
template<typename T>
void    printArray(T& a) {
    std::cout << a << std::endl;
}

//funciones normales(especificas para cada tipo de dato)
void    printIntArray(int x) {
    std::cout << x << std::endl;
}
void    printStringArray(std::string const& string) {
    std::cout << string << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3};
    std::string stringArray[] = {"Hello", "World"};

    //aqui uso una instancia del template (generica para ambos tipos de datos)
    iter(intArray, 3, printArray<int>);
    iter(stringArray, 2, printArray<std::string>);

    //aqui uso las funciones especificas
    iter(intArray, 3, printIntArray);
    iter(stringArray, 2, printStringArray);

    return 0;
}