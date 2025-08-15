#include <ctime>
#include <cstdlib>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    srand(time(NULL));
    
    Bureaucrat becario("Becario", 150);
    Bureaucrat supervisor("Supervisor", 50);
    Bureaucrat jefe("Jefe", 1);

    RobotomyRequestForm robot("Dummy");
    ShrubberyCreationForm tree("Woods");
    PresidentialPardonForm pardon("Político");

    std::cout << std::endl;

    becario.signForm(robot);
    becario.executeForm(robot);
    // becario.signForm(tree);
    // becario.executeForm(tree);
    // becario.signForm(pardon);
    // becario.executeForm(pardon);

    supervisor.signForm(robot);
    supervisor.executeForm(robot);
    // supervisor.signForm(tree);
    // supervisor.executeForm(tree);
    // supervisor.signForm(pardon);
    // supervisor.executeForm(pardon);

    jefe.signForm(robot);
    jefe.executeForm(robot);
    // jefe.signForm(tree);
    // jefe.executeForm(tree);
    // jefe.signForm(pardon);
    // jefe.executeForm(pardon);

    std::cout << std::endl;

    return 0;
}