#include "Bureaucrat.hpp"

int  main() {


    std::cout << "----------------FIRST TEST ------------------" << std::endl;

    try {
        Bureaucrat politico("Politico", 0);
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Capturado: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Capturado: " << e.what() << std::endl;
    }

    std::cout << std::endl << "----------------SECOND TEST ------------------" << std::endl;


    Bureaucrat profe("Profe", 150);
    std::cout << profe << std::endl;
    try {
        profe.decrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
         std::cerr << "Capturado: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Capturado: " << e.what() << std::endl;
    }

    std::cout << std::endl << "----------------THIRD TEST ------------------" << std::endl;


    Bureaucrat boss("The boss", 1);
    std::cout << boss << std::endl;

    try {
        boss.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
         std::cerr << "Capturado: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Capturado: " << e.what() << std::endl;
    }

    std::cout << std::endl << "----------------FOURTH TEST ------------------" << std::endl;

    Bureaucrat normal("Normal", 75);
    std::cout << normal << std::endl;
    normal.incrementGrade();
    std::cout << normal << std::endl;
    normal.decrementGrade();
    std::cout << normal << std::endl;

    std::cout << std::endl << "----------------FOURTH TEST ------------------" << std::endl;

    Bureaucrat random("Random", 5);
    Bureaucrat random2("Random2", 50);
    std::cout << random << std::endl;
    std::cout << random2 << std::endl;
    random.decrementGrade();
    std::cout << random << std::endl;
    random2 = random;
    std::cout << random2 << std::endl;

    std::cout << std::endl << "----------------DESTRUCTORS ------------------" << std::endl;

    return 0;
}