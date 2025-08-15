#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class   Bureaucrat;

class   PresidentialPardonForm : public AForm {
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        void    execute(const Bureaucrat& executor) const;
};

#endif