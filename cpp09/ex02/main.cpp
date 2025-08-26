#include "PmergeMe.hpp"

static long	parseNumber(std::string const& number) {
	
	int i = 0;
	bool space = false;

	if (number.empty())
		throw(std::runtime_error("Error: empty number"));

	while (number[i] && (number[i] == ' ' || number[i] == '	')) 
		i++;

	if (number[i] == '+')
		i++;
	else if (number[i] == '-')
		throw(std::runtime_error("Error: negative number"));
	
	int j = i;
	int z;
	while (number[i]) {
		if (std::isdigit(number[i]) && !space)
			i++;
		else if (number[i] == ' ' || number[i] == '	') {
			if (!space)
				z = i;
			space = true;
			i++;
		}
		else
			throw(std::runtime_error("Error: invalid characters"));
	}

	long n;
	
	if (!space)
		n  = std::atol(number.substr(j, i - j).c_str());
	else if (space)
		n = std::atol(number.substr(j, z - j).c_str());
	
	if (n > __INT_MAX__)
		throw(std::runtime_error("Error: number out of limit"));
		
	return n;
}

static std::vector<int> validateNumbers(char **av) {
	
	int i = -1;
	std::vector<int> vector;

	while (av[++i]) {
		long n = parseNumber(av[i]);
		vector.push_back(static_cast<int>(n));
	}
	
	return vector;
}

static void	printSequence(std::string const& period, std::vector<int>& sequence) {

	std::cout << period << std::endl;

	for (size_t i = 0; i < sequence.size(); i++) {
		std::cout << sequence[i];
		if (i == sequence.size() - 1)
			std::cout << ".";
		else
			std::cout << ", ";
	}
	
	std::cout << std::endl;	
}

int main(int ac, char **av) {
	
	if (ac < 2) {
		std::cerr << "Usage: <program> <at least one number>" << std::endl;
		return 1;
	}

	try {
		std::vector<int> originalSet = validateNumbers(av + 1);

		printSequence("Before: ", originalSet);

		std::vector<int> vector = originalSet;
		std::deque<int> deque(originalSet.begin(), originalSet.end());

		PmergeMe merge;

		clock_t startVector = clock();
		merge.sortVector(vector);
		clock_t endVector = clock();
		
		double vectorDuration = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000.0;
		
		clock_t startDeque = clock();
		merge.sortDeque(deque);
		clock_t endDeque = clock();

		double dequeDuration = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000.0;

		printSequence("After: ", vector);

		//std::cout	<< std::fixed << std::setprecision(5);
		std::cout	<< "Time to process a range of " << vector.size()
		 			<< " elements with std::vector: " << vectorDuration << " us" << std::endl;
		std::cout	<< "Time to process a range of " << deque.size()
		 			<< " elements with std::deque: " << dequeDuration << " us" << std::endl;
				   	
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
