#include "ArrayWrapper.h"

#include <iostream>

int main(int argc, char** argv)
{
    // Dummy data
    int local_array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Get size of array
    size_t size_of_local_array = sizeof(local_array) / sizeof(int);

    // Create ArrayWrapper object
    ArrayWrapper my_array(local_array, size_of_local_array);

    std::cout << "Size of array: " << my_array.size() << std::endl; // Size should be 10

    std::cout << "Element 2: " << my_array[2] << std::endl; // Should print 2

    std::cout << "Element 9: " << my_array[9] << std::endl; // Should print 9

    std::cout << "Sum of 2 and 9 (from array): " << my_array[2] + my_array[9] << std::endl;

    return 0;
}