#include "Span.hpp"

Span::Span() : _maxSize(0), _numbers() {}

Span::Span(unsigned int max_size) : _maxSize(max_size), _numbers() {
    if (_numbers.max_size() < max_size)
        throw MaxNumberException();
}
Span::Span(const Span &copy) : _size(copy._size), _numbers(copy._numbers) {}
Span &Span::operator = (const Span &source) {
    if (this != &source) {
        this->_maxSize = source._maxSize;
        this->_numbers = source._numbers;
    }
    return *this;
}
Span~Span() {}

template <typename T>
void            addNumbers(const T& container) {
    if (sizeof(container) != sizeof(int)) {
        throw IncorrectType();
    }
    if (container.size() + _numbers.size() > _maxSize 
        || container.size() + _numbers.size() > _numbers.max_size())
        throw MaxNumberException();
    _numbers.insert_range(container.begin(), container.end());
}

void            Span::addNumber(int n) {
    if (_numbers.size() + 1  > _maxSize || _numbers.size() + 1 > _numbers.max_size())
        throw MaxNumberException();
    else {
        _numbers.insert(n);
    }
}
void            addRandomNumbers(unsigned int n) {
    if (_numbers.size() + n  > _maxSize || _numbers.size() + n > _numbers.max_size())
        throw MaxNumberException();
    srand(time(NULL));
    for (unsigned int i = 0; i < n; ++i) {

    }
}

std::multiset   Span::getNumbers() const {
    return _numbers;
}

unsigned int    Span::getMaxSize() const {
    return _maxSize;
}

// additional test if the numbers inside multiset are duplicates? 
unsigned int    shortestSpan() const {
    if (_numberes.size() == 1 || _numberes.size() == 0)
        throw NoSpanException();
}
unsigned int    longestSpan() const {
    if (_numberes.size() == 1 || _numberes.size() == 0)
        throw NoSpanException();
}