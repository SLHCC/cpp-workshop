#include "Tree.h"

#include <iostream>

int main() 
{
    // Create root node
    auto root = Tree<int>::makeNode(10);
    // Add left and right children
    root->addLeft(Tree<int>::makeNode(5));
    root->addRight(Tree<int>::makeNode(15));
    // Add grandchildren
    root->left()->addLeft(Tree<int>::makeNode(3));
    root->left()->addRight(Tree<int>::makeNode(7));
    root->right()->addLeft(Tree<int>::makeNode(12));
    root->right()->addRight(Tree<int>::makeNode(18));

    std::cout << "In-order traversal: ";
    root->display();
    std::cout << std::endl;

    // Test copy semantics
    auto copy = Tree<int>::makeNode(*root);
    std::cout << "Copy in-order traversal: ";
    copy->display();
    std::cout << std::endl;

    // Test move semantics
    auto moved = std::move(root);
    std::cout << "Moved in-order traversal: ";
    if (moved) moved->display();
    std::cout << std::endl;

    return 0;
}
