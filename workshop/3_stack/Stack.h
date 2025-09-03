#pragma once

#include <cstddef>
#include <algorithm>
#include <optional>

template<typename T>
class Stack
{
private:
    T* elements;
    size_t stack_ptr;
    size_t elements_size;

    void ensure()
    {
        if (stack_ptr >= elements_size) 
        {
            resize(elements_size == 0 ? 1 : elements_size * 2);
        }
    }

    void adjust()
    {
        if (elements_size > 4 && stack_ptr < elements_size / 4) 
        {
            resize(elements_size / 2);
        }
    }

    void resize(size_t newSize)
    {
        T* newElements = new T[newSize];

        for (size_t i = 0; i < stack_ptr; ++i) 
        {
            newElements[i] = elements ? elements[i] : T{};
        }

        delete[] elements;

        elements = newElements;
        elements_size = newSize;
    }
public:
    Stack() noexcept : elements(nullptr), stack_ptr(0), elements_size(0)
    {
    }
    
    ~Stack()
    {
        delete[] elements;
    }

    Stack(const Stack& other) : Stack()
    {
        for (size_t i = 0; i < stack_ptr; ++i) 
        {
            elements[i] = other.elements[i];
        }
    }

    Stack& operator=(const Stack& other)
    {
        if (this != &other)
        {
            this->~Stack();

            new (this) Stack(other);
        }

        return *this;
    }

    Stack(Stack&& other) : Stack()
    {
        std::swap(elements, other.elements);
        std::swap(elements_size, other.elements_size);
        std::swap(stack_ptr, other.stack_ptr);
    }

    Stack& operator=(Stack&& other)
    {
        if (this != &other)
        {
            std::swap(elements, other.elements);
            std::swap(elements_size, other.elements_size);
            std::swap(stack_ptr, other.stack_ptr);
        }

        return *this;
    }

    void push(const T& element)
    {
        ensure();

        elements[stack_ptr++] = element;
    }

    void pop()
    {
        if (stack_ptr > 0) 
        {
            --stack_ptr;
            adjust();
        }
    }

    std::optional<T> top() const noexcept
    {
        if (stack_ptr > 0)
        {
            return elements[stack_ptr - 1];
        }

        return std::nullopt;
    }
};