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

//aqui multiplicamos por 256 (1 << 8 = 2^8 = 256) para almacenar el numero float como un int desplazado 8 posiciones a la izquierda

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->numberValue = roundf(value * (1 << this->fractionalBits));
}

int Fixed::toInt(void) const {
	return this->numberValue >> this->fractionalBits;
}

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

bool    Fixed::operator>(const  Fixed& other) const {
	return this->numberValue > other.numberValue;
}

bool    Fixed::operator<(const Fixed& other) const {
	return this->numberValue < other.numberValue;
}

bool    Fixed::operator>=(const Fixed& other) const {
	return this->numberValue >= other.numberValue;
}

bool    Fixed::operator<=(const Fixed& other) const {
	return this->numberValue <= other.numberValue;
}

bool    Fixed::operator==(const Fixed& other) const {
	return this->numberValue == other.numberValue;
}

bool    Fixed::operator!=(const Fixed& other) const {
	return this->numberValue != other.numberValue;
}

Fixed   Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->numberValue + other.numberValue);
	return result;
}

Fixed   Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->numberValue - other.numberValue);
	return result;
}

//En multiplicacion y division se shifean los bits para evitar el sobreescalado/infraescalado
//Los valores estan desplazados 8 bits a la izquierda, si multiplicas dos numeros asi el resultado esta shifteado 16 bits
//si divides dos numeros asi desaparecen los desplazamientos

Fixed   Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->numberValue * other.numberValue) >> this->fractionalBits);
	return result;
}

//aqui se shiftea el numerador primero y no el resultado final para que la division no trunque la parte decimal del resultado final

Fixed   Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->numberValue << this->fractionalBits) / other.numberValue);
	return result;
}

//preincremento ++i
//incrementa el valor del objeto y devuelve ese mismo objeto

Fixed& Fixed::operator++(void) {
	this->numberValue++;
	return *this;
}

//postincremento i++
//devuelve una copia del objeto sin incrementar e incrementa el original

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->numberValue++;
	return tmp;
}

Fixed& Fixed::operator--(void) {
	this->numberValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->numberValue--;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	// if (a < b)
	//     return a;
	// else if (a > b)
	//     return b;
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
