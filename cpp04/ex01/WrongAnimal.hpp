#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class   WrongAnimal {
    protected:
    std::string type;
    public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal(void);
    void makeSound() const;
    std::string getType(void) const;
};

#endif
