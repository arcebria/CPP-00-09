#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN {
    private:
        std::stack<int> _stack;

        bool isValidToken(std::string const& token);
        bool isValidNumber(std::string const& token);
        void  performOperation(char op);
        
    public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int calculate(std::string const& expression);
};

#endif