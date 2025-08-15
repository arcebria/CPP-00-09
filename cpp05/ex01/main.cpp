#include "Bureaucrat.hpp"
#include "Form.hpp"

int  main() {
    Bureaucrat random("Burocrata random", 150);
    Form randomFrom("Formulario random", 150, 149);

    random.signForm(randomFrom);

    return 0;
}