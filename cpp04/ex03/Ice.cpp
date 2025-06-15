#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    std::cout << "Ice copy assignment operator called" << std::endl;
    if (this != &other)
        AMateria::operator=(other); // tampoco copiamos aqui por la misma razon
    return *this;
}

Ice::~Ice(void) {
    std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone(void) const {
    std::cout << "Ice materia cloned" << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}