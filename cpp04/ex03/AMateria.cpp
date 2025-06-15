#include "AMateria.hpp"

AMateria::AMateria(void) : _type("Unknown") {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type) {
    std::cout << "AMateria constructor with type called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "AMateria copy assignment operator called" << std::endl;
    if (this != &other) {
        // copiar el type no tiene sentido, de momento solo mostramos el mensaje
        // la estructura se mantiene por si se añaden otros atributos y hace falta copiarlos
    }
    return *this;
}

AMateria::~AMateria(void) {
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const&  AMateria::getType(void) const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "AMateria used on " << target.getName() << std::endl;
}