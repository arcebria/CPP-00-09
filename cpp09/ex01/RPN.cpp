#include "RPN.hpp"

RPN::RPN() : _stack() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isValidNumber(std::string const& token) {
    int i = 0;
    
    while (std::isdigit(token[i]))
        i++;
    int n = std::atoi(token.substr(0, i).c_str());
    
    return n >= 0 && n <= 9;
}

void RPN::performOperation(char op) {
    if (_stack.size() < 2)
        throw(std::runtime_error("Error: Not enough numbers in stack"));

    int second = _stack.top();
    _stack.pop();
    int first = _stack.top();
    _stack.pop();
    
    if (op == '+')
        _stack.push(first + second);
    else if (op == '-')
        _stack.push(first - second);
    else if (op == '*')
        _stack.push(first * second);
    else if (op == '/') {
        if (second == 0)
            throw(std::runtime_error("Error: division by 0 not allowed"));
        _stack.push(first / second);
    }
}

int RPN::calculate(std::string const& line) {
    int i = -1;

    if (line.empty())
        throw(std::runtime_error("Empty input"));

    while (line[++i]) {
        if (line[i] == ' ')
            continue;
        else if (std::isdigit(line[i])) {
            if (isValidNumber(line))
                _stack.push(std::atoi(line.substr(i, 1).c_str()));
            else
                throw(std::runtime_error("Error: number most be beetween 0 and 9"));
        }
        else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
            performOperation(line[i]);
        else
            throw(std::runtime_error("Error: invalid characters"));
    }

    if (_stack.size() != 1)
        throw(std::runtime_error("Error: not enough operands find in input"));
    
    return _stack.top();
}