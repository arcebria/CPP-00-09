#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class   WrongAnimal {
    protected:
    std::string type;
    public:
    WrongAnimal(void);
    ~WrongAnimal(void);
    void makeSound() const;
    std::string getType(void) const;
};

#endif
