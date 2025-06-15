#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class   WrongCat: public WrongAnimal {
    private:
    WrongCat(const WrongCat& other);
    WrongAnimal& operator=(const WrongCat& other);
    public:
    WrongCat(void);
    ~WrongCat(void);
    void    makeSound(void) const;
};

#endif
