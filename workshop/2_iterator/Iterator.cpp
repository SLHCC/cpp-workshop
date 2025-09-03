#include "Iterator.h"

Iterator::Iterator(const std::string& string) noexcept : string(string), it_index(0), string_size(string.length())
{
}

const char& Iterator::operator*() const noexcept
{
    return string[it_index];
}

size_t Iterator::size() const noexcept
{
    return string_size;
}

Iterator& Iterator::operator++() noexcept
{
    it_index++;

    return *this;   
}

Iterator Iterator::operator++(int) noexcept
{
    Iterator i = *this;

    ++(*this);

    return i;
}

bool Iterator::operator==(const Iterator& other_iter) const noexcept
{
    return string == other_iter.string && it_index == other_iter.it_index;
}

Iterator Iterator::begin() noexcept
{
    Iterator i = *this;

    i.it_index = 0;

    return i;
}

Iterator Iterator::end() noexcept
{
    Iterator i = *this;

    i.it_index = string_size;

    return i;
}