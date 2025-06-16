#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else _templates[i] = NULL;
	}
	std::cout << "MaterialSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete _templates[i];
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
			else _templates[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		if (_templates[i]) delete _templates[i];
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return ;
	for (int i = 0; i < 4; i++) {
		if (_templates[i] == NULL) {
			_templates[i] = m->clone();
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return NULL;
}
