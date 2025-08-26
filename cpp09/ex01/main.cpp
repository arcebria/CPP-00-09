#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: <Program name> + <RPN>" << std::endl;
		return 1;
	}

	RPN calculator = RPN();

	try {
		int result = calculator.calculate(av[1]);
		std::cout << "Result is : " << result << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}