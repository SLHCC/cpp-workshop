#pragma once

#include <cstddef>

class ArrayWrapper
{
private:
    int* array;
    size_t array_size;

public:
    ArrayWrapper(int* array = nullptr, size_t array_size = 0) noexcept;

    const int& operator[](size_t index) const noexcept;

    size_t size() const noexcept;
};