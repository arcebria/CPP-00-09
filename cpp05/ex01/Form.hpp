#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class   Bureaucrat;

class Form {
    private:
        std::string const _name;
        bool    _isSigned;
        int const _signGrade;
        int const _executeGrade;
    public:

        Form();
        Form(std::string const& name, int const signGrade, int const executeGrade);
        Form(const Form& other);
        ~Form();
        Form& operator=(const Form& other);

        std::string const& getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void    beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif