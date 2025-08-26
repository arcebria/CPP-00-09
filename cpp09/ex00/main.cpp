#include "ExchangeBitcoin.hpp"

struct ParseResult {
    bool isValid;
    std::string date;
    double value;
    std::string errorMsg;
};

static bool isValidDecimal(std::string const& number) {
	size_t  start = 0;
	bool	hasDot = false;
	bool	hasDigits = false;

	if (number[0] == '+' || number[0] == '-')
		start = 1;
	if (start == number.length())
		return false;
	for (size_t i = start; i < number.length(); i++) {
		if (number[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
			hasDigits = false;
		}
		else if (std::isdigit(number[i]))
			hasDigits = true;
		else 
			return false;
	}
	return hasDigits || hasDot;
}

static bool isValidDate(std::string const& date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (int i = 0; i < 4; i++)
        if (!std::isdigit(date[i])) return false;
    for (int i = 5; i < 7; i++)
        if (!std::isdigit(date[i])) return false;
    for (int i = 8; i < 10; i++)
        if (!std::isdigit(date[i])) return false;
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009) return false; // año en que se creo bitcoin
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day > daysInMonth[month - 1])
        return false;
    return true;
}

static std::string  parseValue(std::string const& line) {
    size_t pos = line.find("|");

    std::string postDelimiter = line.substr(pos + 1);
    size_t i = 0;
    while (postDelimiter[i] == ' ')
        i++;
    size_t j = postDelimiter.length() - 1;
    while (postDelimiter[j] == ' ')
        j--;
    std::string number = postDelimiter.substr(i, j - i + 1);

    return number;
}

static std::string parseDate(std::string const& line) {
    
    size_t i = 0;
    std::string date;
    while (line[i] == ' ')
        i++;
    if (i == 0)
        date = line.substr(0, DATELENGHT);
    else
        date = line.substr(i, DATELENGHT);
    return date;
}

static bool hasDelimiter(std::string const& line) {
    size_t pos = line.find("|");
    if (pos == std::string::npos)
        return false;
    return true;
}

static ParseResult parseLine(std::string const& line) {
    ParseResult result;
    result.isValid = false;
    result.date = "";
    result.value = 0;
    result.errorMsg = "";

    if (!hasDelimiter(line)) {
        result.errorMsg = "Error: bad input ==> " + line;
        return result;
    }

    std::string date = parseDate(line);
    std::string strValue = parseValue(line);

    if (!isValidDate(date) || !isValidDecimal(strValue)) {
        result.errorMsg = "Error: bad input ==> " + date;
        return result;
    }

    double value = std::strtod(strValue.c_str(), NULL);
    if (value < 0) {
        result.errorMsg = "Error: not a positive number.";
        return result;
    }
    if (value > 1000) {
        result.errorMsg = "Error: too large a number.";
        return result;
    }

    result.isValid = true;
    result.date = date;
    result.value = value;
    return result;
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: <Program name> + <input.txt>" << std::endl;
        return 0;
    }

    std::ifstream dataBase("data.csv");
    std::string line;
    std::map<std::string, double> map;
    std::string date;
    double exchangeRate;
    size_t pos;

    std::getline(dataBase, line); //saltamos la primera linea

    if (dataBase.is_open()) { 
        while (std::getline(dataBase, line)) {
            pos = line.find(",");
            date = line.substr(0, pos);
            exchangeRate = std::strtod(line.substr(pos + 1).c_str(), NULL);
            map.insert(std::make_pair(date, exchangeRate));
        }
    }//contenedor map lleno con la base de datos
    else {
        std::cerr << "Error file not open" << std::endl;
        return 1;
    }

    ExchangeBitcoin exchange = ExchangeBitcoin(map);

    std::ifstream input(av[1]);
    
    std::getline(input, line);

    if (input.is_open()) {
        while(std::getline(input, line)) {
            ParseResult parsed = parseLine(line);
            if (!parsed.isValid)
                std::cerr << parsed.errorMsg << std::endl;
            else {
                double result = exchange.calculateExchange(parsed.date, parsed.value);
                if (result != -1)
                    std::cout << parsed.date << " ==> " << parsed.value << " = " << result << std::endl;
                else
                    std::cerr << "Error: bad input ==> " << parsed.date << std::endl;
            }
        }
    }
    else {
        std::cerr << "Error file not open" << std::endl;
        return 1;
    }

    dataBase.close();

    return 0;
}