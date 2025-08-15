#include <ctime>
#include <cstdlib>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    srand(time(NULL));
    
    Bureaucrat jefe("Jefe", 1);
    Intern becario;

	std::cout << std::endl;
    AForm* robot = becario.makeForm("robotomy request", "Employee");
	std::cout << std::endl;
    AForm* tree = becario.makeForm("shrubbery request", "Garden"); 
	std::cout << std::endl;
    AForm* pardon = becario.makeForm("pardon request", "Criminal");
	std::cout << std::endl;
    
    AForm* invalid = becario.makeForm("invalid form", "Target");
	(void)invalid;
    
	std::cout << std::endl;

    if (robot) {
        jefe.signForm(*robot);
        jefe.executeForm(*robot);
		std::cout << std::endl;
        delete robot;
		std::cout << std::endl;
    }
    
    if (tree) {
        jefe.signForm(*tree);
        jefe.executeForm(*tree);
		std::cout << std::endl;
        delete tree;
		std::cout << std::endl;
    }
    
    if (pardon) {
        jefe.signForm(*pardon);
        jefe.executeForm(*pardon);
		std::cout << std::endl;
        delete pardon;
		std::cout << std::endl;
    }

    return 0;
}