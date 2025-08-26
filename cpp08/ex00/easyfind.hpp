#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>

template<typename T>
typename T::iterator easyfind(T& container, int i) {
    typename T::iterator ite = std::find(container.begin(), container.end(), i);

    if (ite == container.end())
        throw (std::runtime_error("Value not found"));
    return ite;
}

#endif