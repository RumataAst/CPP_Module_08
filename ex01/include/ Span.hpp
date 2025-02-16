# ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>

class Span {
private:
    unsigned int _maxInt;

public:
    Span();
    Span(unsigned int max_int);
    Span(const Span &copy);
    Span &operator = (const Span &source);
    ~Span();

    void addNumber();
    void addNumbers();
    shortestSpan();
    longestSpan();

};

class   MaxNumberException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Max number of elements";
        }   
};

class   NoSpanException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "No Span can be found";
        }
};

#endif

