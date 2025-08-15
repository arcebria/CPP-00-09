#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class   Bureaucrat;

class   ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        void execute(const Bureaucrat& executor) const;
};

#endif