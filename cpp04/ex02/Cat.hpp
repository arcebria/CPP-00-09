#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class   Cat: public AAnimal {
    private:
    Brain *catBrain;

    public:
    Cat(void);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat(void);
    void    makeSound(void) const;
};

#endif
