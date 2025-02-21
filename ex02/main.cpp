#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <list>
#include <stack>


int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

// int main()
// {
//     std::list<int> myList;
//     myList.push_back(5);
//     myList.push_back(17);
//     std::cout << myList.back() << std::endl;  // Printing the last element (top of the stack equivalent)
//     myList.pop_back();  // Popping the last element
//     std::cout << myList.size() << std::endl;  // Printing the size of the list
//     myList.push_back(3);
//     myList.push_back(5);
//     myList.push_back(737);
//     myList.push_back(0);

//     // Using an iterator to traverse the list
//     std::list<int>::iterator it = myList.begin();
//     std::list<int>::iterator ite = myList.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     // Creating a stack from the list
//     std::stack<int> s(std::deque<int>(myList.begin(), myList.end()));

//     return 0;
// }