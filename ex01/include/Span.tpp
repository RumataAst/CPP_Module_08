#include "Span.hpp"


template <typename T>
void Span::addNumbers(const T& container) {
    if (_numbers.size() + container.size() > _maxSize) {
        throw MaxNumberException();
    }
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        _numbers.insert(*it);
    }
}