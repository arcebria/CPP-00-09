#include "Functions.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>


int main() {
    std::srand(std::time(NULL));

    for (int i = 0; i < 10; i++) {
        Base* obj = generate();

        std::cout << "Object[" << i << "]" << std::endl;

        std::cout << "Identify type by pointer: ";
        identify(obj);

        std::cout << "Identify type by reference: ";
        identify(*obj);

        delete(obj);
    }
    return 0;
}