#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default Bureaucrat"), _grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : _name(name), _grade(grade) {
    std::cout << "Bureaucrat constructor called" << std::endl;

    if (_grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    else if (_grade < 1)
        throw(Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat operator assignment called" << std::endl;

    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::string const& Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void    Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw(Bureaucrat::GradeTooHighException());
    _grade--;
}

void    Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw(Bureaucrat::GradeTooLowException());
    _grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}