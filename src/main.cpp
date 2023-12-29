#include "trie.hpp"
#include <iostream>
#include <algorithm>

struct TreeNode
{
    int val{0};
    std::unique_ptr<TreeNode> left{};
    std::unique_ptr<TreeNode> right{};

    TreeNode(const int startVal)
    {
        val = startVal;
    }
};

class BinarySearchTree
{

public:
    std::unique_ptr<TreeNode> root{};

    BinarySearchTree(std::vector<int> nodes)
    {
        // Sort the tree so that is will be balanced
        std::sort(nodes.begin(), nodes.end());

        for (auto num : nodes)
        {
            if (!root)
            {
                root = std::make_unique<TreeNode>(TreeNode(num));
            }
            else
            {
                add_node(num);
            }
        }
    }

    /**
     * Does an inorder traversal of the BST to get the sorted order of the nodes based off of their `val` property.
     */
    std::vector<TreeNode *> get_inorder_traversal()
    {
        std::vector<TreeNode *> nodes = {};

        std::function<void(TreeNode *)> traverse_inorder = [&nodes, &traverse_inorder](TreeNode *cur_node) -> void
        {
            if (cur_node)
            {
                traverse_inorder(cur_node->left.get());
                nodes.emplace_back(cur_node);
                traverse_inorder(cur_node->right.get());
            }
        };
        traverse_inorder(root.get());
        return nodes;
    }

    bool add_node(int val)
    {

        std::function<bool(TreeNode *)> traverse_tree = [&traverse_tree, val](TreeNode *cur_node) -> bool
        {
            if (!cur_node)
            {
                return false;
            }

            if (val < cur_node->val)
            {
                bool left_tree = traverse_tree(cur_node->left.get());
                if (!left_tree)
                {
                    cur_node->left = std::make_unique<TreeNode>(TreeNode(val));
                    return true;
                }
            }
            else
            {
                bool right_tree = traverse_tree(cur_node->right.get());
                if (!right_tree)
                {
                    cur_node->right = std::make_unique<TreeNode>(TreeNode(val));
                    return true;
                }
            }
            return true;
        };
        const int has_added = traverse_tree(root.get());
        if (!has_added)
        {
            throw std::invalid_argument("The root node is null");
        }
        return has_added;
    }
};

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
