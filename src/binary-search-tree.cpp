#include "binary-search-tree.hpp"
#include <iostream>

TreeNode::TreeNode(const int startVal) {
    val = startVal;
}

BinarySearchTree::BinarySearchTree(const std::vector<int> &nodes) {
    for (auto num: nodes) {
        if (!root) {
            root = std::make_unique<TreeNode>(TreeNode(num));
        } else {
            add_node(num);
        }
    }
}

std::vector<TreeNode *> BinarySearchTree::get_inorder_traversal() {
    std::vector<TreeNode *> nodes = {};

    std::function<void(TreeNode *)> traverse_inorder = [&nodes, &traverse_inorder](TreeNode *cur_node) -> void {
        if (cur_node) {
            traverse_inorder(cur_node->left.get());
            nodes.emplace_back(cur_node);
            traverse_inorder(cur_node->right.get());
        }
    };
    traverse_inorder(root.get());
    return nodes;
}

bool BinarySearchTree::add_node(int val) {

    std::function<bool(TreeNode *)> traverse_tree = [&traverse_tree, val](TreeNode *cur_node) -> bool {
        if (!cur_node) {
            return false;
        }

        if (val < cur_node->val) {
            bool left_tree = traverse_tree(cur_node->left.get());
            if (!left_tree) {
                cur_node->left = std::make_unique<TreeNode>(TreeNode(val));
                return true;
            }
        } else {
            bool right_tree = traverse_tree(cur_node->right.get());
            if (!right_tree) {
                cur_node->right = std::make_unique<TreeNode>(TreeNode(val));
                return true;
            }
        }
        return true;
    };
    const int has_added = traverse_tree(root.get());
    if (!has_added) {
        throw std::invalid_argument("The root node is null");
    }
    return has_added;
}
