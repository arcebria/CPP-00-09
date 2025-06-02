#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
    Zombie(std::string n);
    ~Zombie();
    void        announce(void);
    std::string getName(void);
};

Zombie*  newZombie(std::string name);
void    randomChump(std::string name);

#endif