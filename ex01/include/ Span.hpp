# ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>

class Span {
private:
    unsigned int    _maxSize;
    std::multiset   _numbers;
public:
    Span();
    Span(unsigned int max_size);
    Span(const Span &copy);
    Span &operator = (const Span &source);
    ~Span();

    template <typename T>
    void            addNumbers(const T& container);
    void            addNumber(int n);
    // addRandomNumbers should take n numbers to add container
    void            addRandomNumbers(unsigned int n);

    std::multiset   getNumbers() const;
    unsigned int    getMaxSize() const;
    unsigned int    shortestSpan() const;
    unsigned int    longestSpan() const;


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

    class   IncorrectType : public std::exception {
        public:
            virtual const char *what() const throw() {
                return "No Span can be found";
            }
    };
};

#endif

