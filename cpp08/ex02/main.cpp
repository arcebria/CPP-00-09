#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "--Mutant Stack results--\n" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n--Vector results--\n" << std::endl;

	std::vector<int> vector;
	vector.push_back(5);
	vector.push_back(17);
	std::cout << vector.back() << std::endl;
	vector.pop_back();
	std::cout << vector.size() << std::endl;
	vector.push_back(3);
	vector.push_back(5);
	vector.push_back(737);
	vector.push_back(0);
	std::vector<int>::iterator vit = vector.begin();
	std::vector<int>::iterator vite = vector.end();
	++vit;
	--vit;
	while (vit != vite) {
		std::cout << *vit << std::endl;
		++vit;
	}
	std::vector<int> v(vector);

	return 0;
}