#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class   AAnimal {
    protected:
    std::string type;
    public:
    AAnimal(void);
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal(void);
    virtual void makeSound() const = 0;
    std::string getType(void) const;
};

#endif
