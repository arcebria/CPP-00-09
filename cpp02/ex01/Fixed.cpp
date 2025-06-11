#include "Fixed.hpp"

Fixed::Fixed(void) : numberValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : numberValue(other.numberValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->numberValue = other.numberValue;
    return (*this);
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

//este constructor almacena el valor del numero pero se desplaza 8 bits a la izquierda
//esto es para "transformarlo en decimmal" ya que los primeros 24 de 32 bits de un float
//se usan para representar el numero entero

Fixed::Fixed(const  int value) {
    std::cout << "Int constructor called" << std::endl;
    this->numberValue = value << this->fractionalBits;
}

//aqui hacemos lo mismo pero con floats no se puede hacer shitft (<<)
//asi que tenemos que multiplicar por 256 (1 << 8 = 2^8 = 256)

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->numberValue = roundf(value * (1 << this->fractionalBits));
}

//desplaza los bits 8 posiciones a la derecha para quedarse con la parte entera
//es lo mismo que dividir entre 256

int Fixed::toInt(void) const {
    return this->numberValue >> this->fractionalBits;
}

//lo mismo pero en vez de hacer shift

float   Fixed::toFloat(void) const {
    return (float)this->numberValue / (1 << this->fractionalBits);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->numberValue;
}

void    Fixed::setRawBits(int const raw) {
    this->numberValue = raw;
}

//el parametro out es std::cout, es decir, el fluujoo de salida estandar
//y el parametro Fixed es el objeto de la clase fixed que queremos imprimir
//luego le decimos que el valor pasado a float del objeto lo inserte en el flujo de salida
//y devuelve ese flujo de salida para encadenar valores
//se utiliza toFloat() porque el valor se guarda como numero de punto fijo, si enviamos un 10 se convertira en un 2560 (numberValue)
//y al convertirlo a float sera un 10 (int), y un 10.1 se convertira en 2585 (numberValue) que al convertirlo a float sera 10.1
//por eso todos los valores de la clase fixed se deben pasar a float

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
