#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default form"), _isSigned(false), _signGrade(150), _executeGrade(150) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const& name, int const signGrade, int const executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    std::cout << "AForm constructor called" << std::endl;

    if (_signGrade > 150 || _executeGrade > 150)
        throw(AForm::GradeTooLowException());
    else if (_signGrade < 1 || _executeGrade < 1)
        throw(AForm::GradeTooHighException());
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << "AForm operator assignment called" << std::endl;

    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

std::string const& AForm::getName() const { return _name; }
bool    AForm::getIsSigned() const { return _isSigned; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecuteGrade() const { return _executeGrade; }

void    AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw(AForm::GradeTooLowException());
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "[Grade is too high]";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "[Grade is too low]";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "[Form not signed]";
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << form.getName() << ". Grade for sign [" << form.getSignGrade()
        << "]. Grade for execute [" << form.getExecuteGrade()
        << "]. Signed: " << form.getIsSigned() << ".";
    
    return out;
}