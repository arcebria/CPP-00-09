#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class   Cat: public Animal {
    private:
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    public:
    Cat(void);
    ~Cat(void);
    void    makeSound(void) const;
};

#endif
