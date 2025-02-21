#include "Span.hpp"
#include "Span.tpp"
#include <vector>

int main() {
    // Create a Span object with a large capacity of 10,000 numbers
    Span sp(10010);

    // Test addNumber() with some predefined numbers
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    // Test addNumbers() with a vector (C++98-style initialization)
    int arr[] = {1, 20, 15};
    std::vector<int> moreNumbers(arr, arr + 3);
    sp.addNumbers(moreNumbers);

    std::cout << "After adding more numbers:" << std::endl;
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    // Test adding a large number of numbers using random values
    std::cout << "Adding random numbers..." << std::endl;
    
    srand(time(0));  // Initialize random seed based on the current time
    
    for (int i = 0; i < 9990; ++i) {  // Add 9990 random numbers
        sp.addNumber(rand() % 10000);  // Random numbers between 0 and 9999
    }

    std::cout << "After adding 9990 random numbers:" << std::endl;
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    // Test addRandomNumbers() with 10 random numbers
    sp.addRandomNumbers(9);  // Add 10 more random numbers
    std::cout << "After adding 10 more random numbers:" << std::endl;
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    // Additional edge case: test with only one element
    Span sp_single(1);
    sp_single.addNumber(50);
    std::cout << "Single element Span:" << std::endl;
    // Since there is only one element, the spans should not be calculable
    try {
        std::cout << "Shortest Span: " << sp_single.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp_single.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;  // Expected behavior
    }

    // Test adding numbers beyond the capacity
    try {
        Span sp_overflow(10);
        sp_overflow.addNumber(1);
        sp_overflow.addNumber(2);
        sp_overflow.addNumber(3);
        sp_overflow.addNumber(4);
        sp_overflow.addNumber(5);
        sp_overflow.addNumber(6);
        sp_overflow.addNumber(7);
        sp_overflow.addNumber(8);
        sp_overflow.addNumber(9);
        sp_overflow.addNumber(10);  // This should work
        sp_overflow.addNumber(11);  // This should throw an exception
    } catch (const std::exception& e) {
        std::cout << "Overflow Test Error: " << e.what() << std::endl;
    }

    return 0;
}