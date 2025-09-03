#include <iostream>
#include <cstddef>

template<size_t N>
struct Cubed
{
    static constexpr size_t value = N * N * N;
};


int main()
{
    constexpr size_t ten_cubed = Cubed<10>::value;

    std::cout << ten_cubed << std::endl;

    return 0;
}