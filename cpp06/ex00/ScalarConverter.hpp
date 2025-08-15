#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iomanip>


class   ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
    public:
        static void    convert(std::string const& literal);
};

#endif