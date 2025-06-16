#include "Character.hpp"

Character::Character(void) : _name("Unknown") {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character default construcor called" << std::endl;
}

Character::Character(std::string const& name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character constructor with string called" << std::endl;
}

Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone(); // creamos una nueva materia, no igualamos los punteros
		else _inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else _inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++)
		if (_inventory[i]) delete _inventory[i];
	std::cout << "Character destructor called" << std::endl;
}

std::string const& Character::getName(void) const {
	return _name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < 4)
		_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "There's no materia equiped in this slot" << std::endl;
}
