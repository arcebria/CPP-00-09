#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;

class Intern {
    private:

    static AForm*  makeRobotomy(std::string const& target);
    static AForm*  makeShrubbery(std::string const& target);
    static AForm*  makePardon(std::string const& target);

    public:

    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    typedef AForm* (*FormCreator)(std::string const& target);


    AForm*  makeForm(std::string const& formName, std::string const& target);
};

#endif