#include "easyfind.hpp"
#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &array, int to_find) {
    typename T::iterator iter;

    iter = std::find(array.begin(), array.end(), to_find);
    if (iter == array.end())
        throw NotFoundException();
    return iter;
};