#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class   Animal {
    protected:
    std::string type;
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    public:
    Animal(void);
    virtual ~Animal(void);
    virtual void makeSound() const;
    std::string getType(void) const;
};

#endif
