#include <string>
#include <iostream>

int	main(void) {
	std::string		originalString = "HI THIS IS BRAIN";
	std::string*	stringPTR = &originalString;
	std::string&	stringREF = originalString;

	std::cout	<< &originalString << "\n"
				<< stringPTR << "\n"
				<< &stringREF << "\n"
				<< originalString << "\n"
				<< *stringPTR << "\n"
				<< stringREF << std::endl;
	return 0;
}
