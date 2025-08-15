#include "ScalarConverter.hpp"

// ScalarConverter::ScalarConverter() {
// }

// ScalarConverter::ScalarConverter(const ScalarConverter& other) {
//     (void)other;
// }

// ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
//     (void)other;
//     return *this;
// }

// ScalarConverter::~ScalarConverter() {
// }

//funciones detectar literales

static bool isValidDecimal(std::string const& literal) {
	size_t  start = 0;
	bool	hasDot = false;
	bool	hasDigits = false;

	if (literal[0] == '+' || literal[0] == '-')
		start = 1;
	if (start == literal.length())
		return false;
	//descomentar estas lineas si no queremos aceptar .42 como valido
	// if (literal[start] == '.')
	// 	return flase;
	for (size_t i = start; i < literal.length(); i++) {
		if (literal[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
			hasDigits = false;
		}
		else if (std::isdigit(literal[i]))
			hasDigits = true;
		else
			return false;
	}
	return hasDot && hasDigits;
	//probar 42.f creo que lo dara como bueno, si es asi añadir que despues de comprobar el punto ponga hasDigit en false
}

static bool isFloat(std::string const& literal) {
	if (literal.empty())
		return false;
	if (literal[literal.length() - 1] != 'f')
		return false;
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	
	std::string number = literal.substr(0, literal.length() - 1);

	return isValidDecimal(number);
}

static bool isDouble(std::string const& literal) {
	if (literal.empty())
		return false;
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	if (literal[literal.length() - 1] == 'f')
		return false;
	
	return isValidDecimal(literal);
}

static bool isChar(std::string const& literal) {
	if (literal.empty())
		return false;

	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return true;
	return false;
}

static bool isInt(std::string const& literal) {
	if (literal.empty())
		return false;

	size_t start = 0;
	if (literal[0] == '+' || literal[0] == '-')
		start = 1;
	
	if (start == literal.length())
		return false;
	
	for (size_t i = start; i < literal.length(); i++) {
		if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}

// funciones printear literales

static void	printChar(double value) {
	std::cout << "char: ";

	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible" << std::endl;
	else if (value < 32 || value > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void	printInt(double value) {
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value) {
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << ((value < 0) ? "-inff" : "+inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value) {
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << ((value < 0) ? "-inf" : "+inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

static void printAllTypes(double value) {
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

void ScalarConverter::convert(std::string const& literal) {
	if (isChar(literal)) {
		char c = literal[1];
		printAllTypes(static_cast<double>(c));
	}
	else if (isInt(literal)) {
		long i = std::atol(literal.c_str());
		if (i > INT_MAX || i < INT_MIN) {
			std::cout << "Error: Integer overflow" << std::endl;
			return ;
		}
		printAllTypes(static_cast<double>(i));
	}
	else if (isFloat(literal)) {
		float f = std::strtof(literal.c_str(), NULL);
		printAllTypes(static_cast<double>(f));
	}
	else if (isDouble(literal)) {
		double d = std::strtod(literal.c_str(), NULL);
		printAllTypes(d);
	}
	else
		std::cout << "Error: Invalid literal format" << std::endl;
}