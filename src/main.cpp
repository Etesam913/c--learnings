#include "binary-search-tree.hpp"
#include <iostream>
#include <algorithm>

int main()
{
    BinarySearchTree tree = BinarySearchTree({2, 10, 3, 5});

    const auto inorder_nodes = tree.get_inorder_traversal();
    for (auto node : inorder_nodes)
    {
        std::cout << node->val << "\n";
    }
    return 0;
}
