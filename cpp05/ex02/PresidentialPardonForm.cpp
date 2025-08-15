#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Presidential Pardon Form", 25, 5), _target("Default target") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm operator assignment called" << std::endl;

    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (getIsSigned() == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException();
    
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

