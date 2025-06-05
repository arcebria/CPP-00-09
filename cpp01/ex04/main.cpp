#include <string>
#include <iostream>
#include <fstream>

std::string	processLine(std::string line, std::string s1, std::string s2) {
	std::string result;
	int i = 0;
	while (line[i]) {
		std::size_t pos = line.find(s1, i);
		if (pos < line.length()) {
			result += line.substr(i, pos - i) + s2;
			i = pos + s1.length();
		}
		else {
			result = result + line.substr(i);
			break;
		}
	}
	return result;
}

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Incorrect amount of arguments" << std::endl;
		return 1;
	}

	std::ifstream	inputFile(av[1]);
	if (!inputFile.is_open())
		std::cerr << "Is not possible to open " << av[1] << std::endl;
	std::string line;
	std::string filename =  av[1];
	filename += ".replace";
	std::fstream outputFile(filename.c_str(), std::ios::app);
	if (!outputFile.is_open())
		std::cerr << "Is not possible to open " << filename << std::endl;
	while(std::getline(inputFile, line)) {
		line = processLine(line, av[2], av[3]);
		outputFile << line << std::endl;
	}
	inputFile.close();
	return 0;
}
