# ifndef EASY_FIND_HPP
#define EASY_FIND_HPP
#include <exception>

template<typename T>
typename T::iterator easyfind(T &array, int to_find);


class NotFoundException : public std::exception{
public:
    virtual const char *what() const throw() {
        return "Element not found";
    }   
};

#endif