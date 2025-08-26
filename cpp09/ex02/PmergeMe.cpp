#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other)
		(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}



std::vector<int> PmergeMe::generateJacobsthalSequence(int N) {
	std::vector<int> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	std::vector<int> order;
	order.push_back(0);
	
	while (jacobsthal.back() < N) {
		int next = jacobsthal.back() + 2 * jacobsthal[static_cast<int>(jacobsthal.size()) - 2]; //J(n) = J(n - 1) + 2 * J(n - 2)
		jacobsthal.push_back(next);
	}
	
	// if (N > 0)
	// 	order.push_back(0);
	
	for (size_t i = 2; i < jacobsthal.size() - 1; i++) {
		int start = jacobsthal[i - 1] + 1;
		int end = std::min(jacobsthal[i], N - 1);
		
		for (int j = end; j >= start; j--)
		order.push_back(j);
	}
	
	//este metodo no te asegura que el tamaño de order sea el mismo que secondary
	//puede queadar un indice por añadirse
	// aqui creamos un vector de booleanos que recorre order, detecta el indice que falta y lo añade al final
	
	std::vector<bool> used(N, false);
	for (size_t i = 0; i < order.size(); i++)
	used[order[i]] = true; // ponemos en true solo los indices que contiene order (p.j 0, 3, 2, 4) el indice 1 quedaria false que es el que falta por añadir
	
	for (size_t i = 0; i < used.size(); i++) {
		if (used[i] == false) // si al recorrer used encontramos un indice falso se añade a order porque es el que falta
		order.push_back(i);
	}
	
	return (order);
}

//estos metodos van buscando la posicion correcta para insertar el numero de secondary dentro de main
//si el numero es menor que la posicion que marca mid este avanza hacia la izquierda
//si es mayor mid avanza a la derecha
//al ir modificando mid se modifica left y right y se encuentra la posicion correcta representada en left
int PmergeMe::vectorInsertPosition(std::vector<int>& main, int value) {
	
	int left = 0;
	int right = main.size() - 1;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		if (main[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	
	return left;
}

int PmergeMe::dequeInsertPosition(std::deque<int>& main, int value) {

	int left = 0;
	int right = main.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (main[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return left;
}

//estos metodos van ordenando y mientras vuelven a formar los chunks separados en sorted
//recorren los dos chunks al mismo tiempo mientras van añadiendo a sorted los menores de cada comparacion
std::vector<std::pair<int,int> > PmergeMe::mergeVectorPairs(std::vector<std::pair<int,int> >& left, std::vector<std::pair<int,int> >& right) {

	std::vector<std::pair<int,int> > sorted;
	size_t i = 0, j = 0;

	while (i < left.size() && j < right.size()) {
		if (left[i].first < right[j].first) {
			sorted.push_back(left[i]);
			i++;
		}
		else {
			sorted.push_back(right[j]);
			j++;
		}
	}

	while (i < left.size()) {
		sorted.push_back(left[i]);
		i++;
	}
	while (j < right.size()) {
		sorted.push_back(right[j]);
		j++;
	}

	return sorted;
}

std::deque<std::pair<int, int> > PmergeMe::mergeDequePairs(std::deque<std::pair<int,int> >& left, std::deque<std::pair<int,int> >& right) {
	
	std::deque<std::pair<int,int> > sorted;
	size_t i = 0, j = 0;

	while (i < left.size() && j < right.size()) {
		if (left[i].first < right[j].first) {
			sorted.push_back(left[i]);
			i++;
		}
		else {
			sorted.push_back(right[j]);
			j++;
		}
	}

	while (i < left.size()) {
		sorted.push_back(left[i]);
		i++;
	}
	while (j < right.size()) {
		sorted.push_back(right[j]);
		j++;
	}

	return sorted;
}

//metodos que van separando los chunks a la mitad recursivamente y luego va llamando la funcion que los junta ordenandolos
//la primera llamada a merge ordena dos chunks de un numero, luego dos chunks de dos numeros(previamente ordenados)...
//se hace con el main y secondary ligado porque cuando se ordene main, los pares de secondary deben permanecer unidos para la segunda parte del algoritmo
std::vector<std::pair<int,int> > PmergeMe::sortVectorPairsMain(std::vector<std::pair<int,int> >& pairs) {
	
	if (pairs.size() < 2)
		return pairs;
	
	size_t midPoint = pairs.size() / 2;
	std::vector<std::pair<int,int> > midLeft;
	std::vector<std::pair<int,int> > midRight;
	for (size_t i = 0; i < midPoint; i++)
		midLeft.push_back(pairs[i]);
	for (size_t i = midPoint; i < pairs.size(); i++)
		midRight.push_back(pairs[i]);
	
	std::vector<std::pair<int,int> > leftSorted = sortVectorPairsMain(midLeft);
	std::vector<std::pair<int,int> > rightSorted = sortVectorPairsMain(midRight);

	return mergeVectorPairs(leftSorted, rightSorted);
}
//same as arriba
std::deque<std::pair<int,int> > PmergeMe::sortDequePairsMain(std::deque<std::pair<int,int> >& pairs) {

	if (pairs.size() < 2)
		return pairs;
	
	size_t midPoint = pairs.size() / 2;
	std::deque<std::pair<int,int> > midLeft;
	std::deque<std::pair<int,int> > midRight;
	for (size_t i = 0; i < midPoint; i++)
		midLeft.push_back(pairs[i]);
	for (size_t i = midPoint; i < pairs.size(); i++)
		midRight.push_back(pairs[i]);
	
	std::deque<std::pair<int,int> > leftSorted = sortDequePairsMain(midLeft);
	std::deque<std::pair<int,int> > rightSorted = sortDequePairsMain(midRight);

	return mergeDequePairs(leftSorted, rightSorted);
}

//metodos para ligar en pares los numeros del contenedor tal cual nos lo dan
void PmergeMe::makeVectorPairs(std::vector<int>& vector, std::vector<std::pair<int, int> >& pairs, int& straggler){
	
	//recorremos vector de dos en dos
	for (size_t i = 0; i < vector.size(); i += 2) {
		if (i + 1 < vector.size()) {
			int a = vector[i];
			int b = vector[i + 1];
			
			//ponemos el mayor en primer lugar(main) y el menor en segundo lugar(secondary)
			if (a > b)
				pairs.push_back(std::make_pair(a, b));
			else
				pairs.push_back(std::make_pair(b, a));
		}
		//si encontramos un numero cuyo par no existe lo guardamos en straggler(rezagado)
		else
			straggler = vector[i];
	}
}
//same as lo de arriba
void PmergeMe::makeDequePairs(std::deque<int>& deque, std::deque<std::pair<int,int> >& pairs, int& straggler) {

	for (size_t i = 0; i < deque.size(); i+= 2) {
		if (i + 1 < deque.size()) {
			int a = deque[i];
			int b = deque[i + 1];

			if (a > b)
				pairs.push_back(std::make_pair(a, b));
			else
				pairs.push_back(std::make_pair(b, a));
		}
		else
			straggler = deque[i];
	}
}

//metodos principales donde se llaman a todos los demas metodos
void PmergeMe::sortVector(std::vector<int>& vector) {
	std::vector<std::pair<int,int> > pairs;
	std::vector<int> main;
	std::vector<int> secondary;
	int straggler = -1;
	
	if (vector.size() == 1) {
		std::cout << vector[0] << std::endl;
		return;
	}

	makeVectorPairs(vector, pairs, straggler);
	pairs = sortVectorPairsMain(pairs);

	for (size_t i = 0; i < pairs.size(); i++) {
		main.push_back(pairs[i].first);
		secondary.push_back(pairs[i].second);
	}

	std::vector<int> orderedSequence = generateJacobsthalSequence(static_cast<int>(secondary.size()));

	for (size_t i = 0; i < orderedSequence.size(); i++) {
		int value = secondary[orderedSequence[i]];
		int pos = vectorInsertPosition(main, value);
		main.insert(main.begin() + pos, value);
	}

	// insertar el numero rezagado
	if (straggler != -1) {
		int stragglerPos = vectorInsertPosition(main, straggler);
		main.insert(main.begin() + stragglerPos, straggler);
	}

	vector = main;
}

void	PmergeMe::sortDeque(std::deque<int>& deque) {
	std::deque<std::pair<int,int> > pairs;
	std::deque<int>	main;
	std::deque<int>	secondary;
	int straggler = -1;

	if (deque.size() == 1) {
		std::cout << deque[0] << std::endl;
		return;
	}

	makeDequePairs(deque, pairs, straggler);
	pairs = sortDequePairsMain(pairs);

	for (size_t i = 0; i < pairs.size(); i++) {
		main.push_back(pairs[i].first);
		secondary.push_back(pairs[i].second);
	}

	std::vector<int> orderedSequence = generateJacobsthalSequence(static_cast<int>(secondary.size()));

	for (size_t i = 0; i < orderedSequence.size(); i++) {
		int value = secondary[orderedSequence[i]];
		int pos = dequeInsertPosition(main, value);
		main.insert(main.begin() + pos, value);
	}

	if (straggler != -1) {
		int stragglerPos = dequeInsertPosition(main, straggler);
		main.insert(main.begin() + stragglerPos, straggler);
	}

	deque = main;
}