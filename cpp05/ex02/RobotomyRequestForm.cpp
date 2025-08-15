#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Robotomy Request Form", 72, 45), _target("Default target") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : AForm("Robotomy Request Form", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "RobotomyRequestForm operator assignment called" << std::endl;

	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();

	std::cout << "*Drilling noises*" << std::endl;

	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}