#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>


int main() {
	std::vector<int> vector;
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	std::list<int> list;
	list.push_back(10);
	list.push_back(20);
	list.push_back(30);

	std::deque<int> deque;
	deque.push_back(100);
	deque.push_back(200);
	deque.push_back(300);


	try {
		std::vector<int>::iterator i= easyfind(vector, 1);
		std::cout << "Numero encontrado: " << *i << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator j = easyfind(list, 10);
		std::cout << "Numero encontrado: " << *j << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	 
	try {
		std::deque<int>::iterator z = easyfind(deque, 100);
		std::cout << "Numero encontrado: " << *z << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}