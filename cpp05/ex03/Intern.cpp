#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern operator assignment called" << std::endl;
	if (this != &other) {
		;
	}
	(void)other;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeRobotomy(std::string const& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeShrubbery(std::string const& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makePardon(std::string const& target) {
	return new PresidentialPardonForm(target);
}

AForm*  Intern::makeForm(std::string const& formName, std::string const& target) {

	std::string	forms[3] = {
		"robotomy request",
		"shrubbery request",
		"pardon request"
	};

	FormCreator creators[3] = {
		makeRobotomy,
		makeShrubbery,
		makePardon
	};

	for (int i = 0; i < 3; i++) {
		if (formName == forms[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}

	std::cout << "Error: Unknown form name [" << formName << "]" << std::endl;
	return NULL;
}
