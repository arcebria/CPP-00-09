#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include "WrongAnimal.hpp"

class   WrongDog: public WrongAnimal {
    public:
    WrongDog(void);
    WrongDog(const WrongDog& other);
    WrongDog& operator=(const WrongDog& other);
    ~WrongDog(void);
    void    makeSound(void) const;
};

#endif
