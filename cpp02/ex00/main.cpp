#include "Fixed.hpp"

int main( void ) {
    //crea objeto con valor 0
    Fixed a;
    //crea una copia de a en b
    Fixed b( a );
    //crea otro objeto con valor 0
    Fixed c;
    //asigna el valor de 'b' a 'c'
    c = b;
    //printea los valores de a, b y c
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}

