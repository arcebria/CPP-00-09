#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
    Zombie();
    ~Zombie();
    void        announce(void);
    std::string getName(void);
    void    setName(std::string name);
};

Zombie* zombieHorde(int n, std::string name);

#endif