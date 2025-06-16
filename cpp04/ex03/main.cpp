#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void) {
    IMateriaSource* source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());

    ICharacter* cloud = new Character("Cloud");

    AMateria* iceMateria = source->createMateria("ice");
    AMateria* cureMateria = source->createMateria("cure");
    cloud->equip(iceMateria);
    cloud->equip(cureMateria);

    ICharacter* randomSoldier = new Character("Random Soldier");

    cloud->use(0, *randomSoldier);

    delete cloud;
    delete randomSoldier;
    delete source;

    return 0;
}