#pragma once

#include <string>

class Iterator
{
private:
    std::string string;
    size_t it_index;
    size_t string_size;

public:
    Iterator(const std::string& string) noexcept;

    const char& operator*() const noexcept;

    size_t size() const noexcept;

    Iterator& operator++() noexcept;
    Iterator operator++(int) noexcept;

    bool operator==(const Iterator& other_iter) const noexcept;

    Iterator begin() noexcept;
    Iterator end() noexcept;
};

