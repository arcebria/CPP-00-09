#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class   Dog: public Animal {
    private:
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    public:
    Dog(void);
    ~Dog(void);
    void    makeSound(void) const;
};

#endif
