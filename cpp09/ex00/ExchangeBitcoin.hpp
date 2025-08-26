#ifndef EXCHANGEBITCOIN_HPP
#define EXCHANGEBITCOIN_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>
#define DATELENGHT 10

class   ExchangeBitcoin {
    private:
        std::map<std::string, double> _map;
    public:
        ExchangeBitcoin();
        ExchangeBitcoin(std::map<std::string, double> map);
        ExchangeBitcoin(const ExchangeBitcoin& other);
        ExchangeBitcoin& operator=(const ExchangeBitcoin& other);
        ~ExchangeBitcoin();

        double  calculateExchange(std::string const& date, double value);
        double  findRatio(std::string const& date);
};

#endif