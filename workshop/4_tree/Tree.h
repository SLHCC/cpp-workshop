#pragma once

#include <iostream>
#include <memory>
#include <algorithm>

// Please note this is a binary or 2-Ary tree
template<typename T>
class Tree
{
public:
    using Node = std::unique_ptr<Tree<T>>;

    Tree(const T& data) noexcept : data(data), nodes(nullptr)
    {
    }

     // Copy constructor
    Tree(const Tree& other) : data(other.data)
    {
        if (other.hasLeft()) nodes[0] = std::make_unique<Tree>(*other.nodes[0]);
        if (other.hasRight()) nodes[1] = std::make_unique<Tree>(*other.nodes[1]);
    }

    // Copy assignment
    Tree& operator=(const Tree& other)
    {
        if (this != &other) 
        {
            data = other.data;
            nodes[0] = other.nodes[0] ? std::make_unique<Tree>(*other.nodes[0]) : nullptr;
            nodes[1] = other.nodes[1] ? std::make_unique<Tree>(*other.nodes[1]) : nullptr;
        }

        return *this;
    }
    // Move constructor
    Tree(Tree&& other) noexcept : data(std::move(other.data))
    {
        std::swap(left(), other.left());
        std::swap(right(), other.right());
        std::swap(data, other.data);
    }

    // Move assignment
    Tree& operator=(Tree&& other) noexcept
    {
        if (this != &other) 
        {
            std::swap(left(), other.left());
            std::swap(right(), other.right());
            std::swap(data, other.data);
        }
        
        return *this;
    }

    template<typename... Args>
    static Node makeNode(Args&&... args)
    {
        return std::make_unique<Tree>(std::forward<Args>(args)...);
    }
    
    T operator*() const noexcept
    {
        return data;
    }

    Node& left() noexcept { return nodes[0]; }
    Node& right() noexcept { return nodes[1]; }

    bool hasLeft() const noexcept
    {
        return nodes[0] != nullptr;
    }

    bool hasRight() const noexcept
    {
        return nodes[1] != nullptr;
    }

    void addLeft(Node node) noexcept
    {
        nodes[0] = std::move(node);
    }

    void addRight(Node node) noexcept
    {
        nodes[1] = std::move(node);
    }

    Node removeLeft() noexcept
    {
        return std::move(nodes[0]);
    }
    Node removeRight() noexcept
    {
        return std::move(nodes[1]);
    }

    void display() const noexcept
    {
        std::cout << "{" << data;

        if (hasLeft() || hasRight()) 
        {
            std::cout << ": ";
            if (hasLeft())
            {
                nodes[0]->display();
            }
        
            std::cout << ", ";
            if (hasRight())
            {
                nodes[1]->display();
            }
        }

        std::cout << "}";
    }

private:
    T data;
    Node nodes[2];
};