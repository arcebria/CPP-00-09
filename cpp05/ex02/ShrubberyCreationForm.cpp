#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrubbery", 145, 137), _target("DefaultTarget") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "ShrubberyCreationForm operator assignment called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void    ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();

	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Couldn't create the file");
	
	file	<< "      /\\      " << std::endl;
	file	<< "     /  \\     " << std::endl;
	file	<< "    /    \\    " << std::endl;
	file	<< "   /      \\   " << std::endl;
	file	<< "  /        \\  " << std::endl;
	file	<< " /__________\\ " << std::endl;
	file	<< "      ||      " << std::endl;

	file.close();
}