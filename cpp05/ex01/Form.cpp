#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default form"), _isSigned(false), _signGrade(150), _executeGrade(150) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const& name, int const signGrade, int const executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    std::cout << "Form constructor called" << std::endl;

    if (_signGrade > 150 || _executeGrade > 150)
        throw(Form::GradeTooLowException());
    else if (_signGrade < 1 || _executeGrade < 1)
        throw(Form::GradeTooHighException());
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form operator assignment called" << std::endl;

    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

std::string const& Form::getName() const { return _name; }
bool    Form::getIsSigned() const { return _isSigned; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecuteGrade() const { return _executeGrade; }

void    Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw(Form::GradeTooLowException());
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << form.getName() << ". Grade for sign [" << form.getSignGrade()
        << "]. Grade for execute [" << form.getExecuteGrade()
        << "]. Signed: " << form.getIsSigned() << ".";
    
    return out;
}