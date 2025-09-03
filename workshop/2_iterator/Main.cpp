#include "Iterator.h"

#include <iostream>

int main(int argc, char** argv)
{
    Iterator iter("Swinburne Linux Hardware and Code Club");

    // Test iterator
    for ( ; iter != iter.end(); iter++ )
    {
        std::cout << "Current char: " << *iter << std::endl; // Print current character
    }

    return 0;
}