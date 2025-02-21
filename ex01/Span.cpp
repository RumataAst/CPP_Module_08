#include "Span.hpp"

Span::Span() : _maxSize(0), _numbers() {}

Span::Span(unsigned int max_size) : _maxSize(max_size), _numbers() {
    if (_numbers.max_size() < max_size)
        throw MaxNumberException();
}

Span::Span(const Span &copy) : _maxSize(copy._maxSize), _numbers(copy._numbers) {}

Span &Span::operator = (const Span &source) {
    if (this != &source) {
        this->_maxSize = source._maxSize;
        this->_numbers = source._numbers;
    }
    return *this;
}
Span::~Span() {}

template <typename T>
void            Span::addNumbers(const T& container) {
    if (sizeof(container) != sizeof(int)) {
        throw IncorrectType();
    }
    if (container.size() + _numbers.size() > _maxSize 
        || container.size() + _numbers.size() > _numbers.max_size())
        throw MaxNumberException();
    
    _numbers.insert(container.begin(), container.end());
}

void            Span::addNumber(int n) {
    if (_numbers.size() + 1  > _maxSize || _numbers.size() + 1 > _numbers.max_size())
        throw MaxNumberException();
    else {
        _numbers.insert(n);
    }
}
void                Span::addRandomNumbers(unsigned int n) {
    if (_numbers.size() + n  > _maxSize || _numbers.size() + n > _numbers.max_size())
        throw MaxNumberException();
    srand(time(NULL));
    int random_variable = 0;
    for (unsigned int i = 0; i < n; ++i) {
        random_variable = rand();
        _numbers.insert(random_variable);
    }
}

std::multiset<int>  Span::getNumbers() const {
    return _numbers;
}

unsigned int    Span::getMaxSize() const {
    return _maxSize;
}

unsigned int    Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw NoSpanException();
    
    unsigned int    minSpan = std::numeric_limits<unsigned int>::max();
    std::multiset<int>::const_iterator it = _numbers.begin();
    std::multiset<int>::const_iterator itNext = it;
    ++itNext;

    while (itNext != _numbers.end()) {
        unsigned int diff = *itNext - *it;
        if (diff < minSpan) {
            minSpan = diff;
        }
        ++it;
        ++itNext;
    }
    return minSpan;
}

unsigned int    Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw NoSpanException();
    return *(_numbers.rbegin()) - *(_numbers.begin());
}