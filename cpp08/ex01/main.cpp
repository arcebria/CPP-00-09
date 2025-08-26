#include "Span.hpp"

int main()
{   
    Span sp = Span(7);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n----Testing addRange method----" << std::endl;
    std::vector<int> numbers;

    numbers.push_back(3);
    numbers.push_back(20);
    sp.addRange(numbers.begin(), numbers.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n----Testing maxSize limit----" << std::endl;
    try {
        sp.addNumber(0);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n----Testing span with less than 2 numbers----" << std::endl;
    Span sp2 = Span();
    try {
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}