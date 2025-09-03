#include "ArrayWrapper.h"

#include <cassert>

ArrayWrapper::ArrayWrapper(int* array, size_t array_size) noexcept : array(array), array_size(array_size)
{
}

const int& ArrayWrapper::operator[](size_t index) const noexcept
{
    assert(index < array_size);

    return array[index];
}

size_t ArrayWrapper::size() const noexcept
{
    return array_size;
}