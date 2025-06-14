#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class   Animal {
    protected:
    std::string type;
    public:
    //!!PONER LO DE LA FORMA CANONICA DE LOS COJONES!!
    Animal(void);
    virtual ~Animal(void);
    virtual void makeSound() const;
    std::string getType(void) const;
};

#endif
