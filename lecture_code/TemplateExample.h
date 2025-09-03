#pragma once

#include <cstddef>

template<typename T, size_t N>
class TemplateExample
{
private:
    T* elements;
    N size;

public:
    TemplateExample() noexcept;

    N size() const noexcept;
};

