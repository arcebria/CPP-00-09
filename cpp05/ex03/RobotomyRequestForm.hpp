#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class   Bureaucrat;

class   RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void execute(const Bureaucrat& executor) const;
};

#endif