#include "ExchangeBitcoin.hpp"

ExchangeBitcoin::ExchangeBitcoin() : _map() {}

ExchangeBitcoin::ExchangeBitcoin(std::map<std::string, double> map) : _map(map) {}

ExchangeBitcoin::ExchangeBitcoin(const ExchangeBitcoin& other) : _map(other._map) {}

ExchangeBitcoin& ExchangeBitcoin::operator=(const ExchangeBitcoin& other) {
    if (this != &other)
        _map = other._map;
    return *this;
}

ExchangeBitcoin::~ExchangeBitcoin() {}

double  ExchangeBitcoin::findRatio(std::string const& date) {
    
    std::map<std::string, double>::iterator it = _map.lower_bound(date);
    
    if (it != _map.end() && it->first == date)
        return it->second;
    else if (it == _map.begin())
        return -1;
    it--;
    return it->second;
}

double ExchangeBitcoin::calculateExchange(std::string const& date, double value) {
    double  ratio = findRatio(date);
    if (ratio != -1)
        return ratio * value;
    else
        return -1;
}

