#include "easyfind.hpp"
#include "easyfind.tpp"
#include  <algorithm>
#include <iostream>
#include <vector>

int main(void){
    std::vector<int> myints;
    myints.push_back(10);
    myints.push_back(15);
    myints.push_back(30);
    myints.push_back(50);

    for (std::vector<int>::iterator iter = myints.begin(); iter != myints.end(); ++iter) {
        std::cout << "Address of the iterator " << &iter
            << " address of element: " << &(*iter) 
            << " and value: " << *iter << std::endl;
    }

    try {
        std::cout << "\nLooking for 10\n";
        std::vector<int>::iterator iter1 = easyfind(myints, 10);
        std::cout << "Address of the iterator " << &iter1 << std::endl;
        std::cout << "address of the value " << &(*(iter1)) << std::endl;
        std::cout << "and value " << *iter1 << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "\nLooking for element that is not in the vector\n";    
        std::vector<int>::iterator iter2 = easyfind(myints, 42);
        std::cout << "Address of the iterator " << &iter2 << std::endl;
        std::cout << "address of the value " << &(*(iter2)) << std::endl;
        std::cout << "and value " << *iter2 << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

