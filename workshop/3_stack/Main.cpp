#include "Stack.h"

#include <iostream>

int main()
{
    Stack<size_t> s;

    for ( size_t i = 0; i < 16; i++ )
    {
        std::cout << "Adding element: " << i << std::endl;
        s.push(i);
    }

    std::cout << "Element at top is: " << s.top().value() << std::endl;

    for ( size_t i = 0; i < 16; i++ )
    {
        std::cout << "Pop count: " << i << std::endl;
        s.pop();
    }

    return 0;
}