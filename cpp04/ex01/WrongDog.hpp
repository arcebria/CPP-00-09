#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include "WrongAnimal.hpp"

class   WrongDog: public WrongAnimal {
    private:
    WrongDog(const WrongDog& other);
    WrongDog& operator=(const WrongDog& other);
    public:
    WrongDog(void);
    ~WrongDog(void);
    void    makeSound(void) const;
};

#endif
