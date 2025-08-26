#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iomanip>

class   PmergeMe {
	private:
		//la secuencia de jacobstal no hace falta repetirla con otro contenedor porque no afecta a los movimientos internos del contenedor
		//solamente nos da una secuencia de insercion del contenedor secondary a main. No afecta a los contenedores simplemente nos da un orden de ordenacion
		std::vector<int> generateJacobsthalSequence(int N); 
		
		//metodos privados para vector
		void makeVectorPairs(std::vector<int>& vector, std::vector<std::pair<int, int> >& pairs, int& straggler);
		std::vector<std::pair<int,int> > sortVectorPairsMain(std::vector<std::pair<int,int> >& pairs);
		std::vector<std::pair<int,int> > mergeVectorPairs(std::vector<std::pair<int,int> >& left, std::vector<std::pair<int,int> >& right);
		int	vectorInsertPosition(std::vector<int>& main, int value);

		//metodos privados para deque
		void makeDequePairs(std::deque<int>& deque, std::deque<std::pair<int, int> >& pairs, int& straggler);
		std::deque<std::pair<int,int> > sortDequePairsMain(std::deque<std::pair<int,int> >& pairs);
		std::deque<std::pair<int,int> > mergeDequePairs(std::deque<std::pair<int,int> >& left, std::deque<std::pair<int,int> >& right);
		int	dequeInsertPosition(std::deque<int>& main, int value);


	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void    sortVector(std::vector<int>& vector);
		void	sortDeque(std::deque<int>& deque);
};

//aclaracion sobre std::pair. Esto no es un contenedor STL simplemente una estructura de datos que almacena dos elementos

#endif