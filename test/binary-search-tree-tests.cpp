#include <gtest/gtest.h>
#include "binary-search-tree.hpp"


TEST(binary_search_tree, adds_nodes_successfully) {
    BinarySearchTree bst = BinarySearchTree({1, 2, 3, -5, -2});
    ASSERT_TRUE(bst.add_node(10));
    ASSERT_TRUE(bst.add_node(4));
}

TEST(binary_search_tree, gets_inorder_traversal_successfully) {
    BinarySearchTree bst = BinarySearchTree({1, 2, 3, -5, -2});
    bst.add_node(10);
    bst.add_node(4);

    const std::vector<int> expected_traversal = {-5, -2, 1, 2, 3, 4, 10};

    auto actual_traversal = bst.get_inorder_traversal();

    for (int i = 0; i < actual_traversal.size(); i++) {
        EXPECT_EQ(actual_traversal[i]->val, expected_traversal[i]);
    }
}
