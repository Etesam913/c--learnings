#include "trie.hpp"
#include <iostream>

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
private:
    std::unique_ptr<TreeNode> root{};

public:
    BinarySearchTree(const int val, const std::vector<int> &nodes)
    {
        // root.val = val;
        for (auto num : nodes)
        {
            if (!root)
            {
                root = std::make_unique<TreeNode>(TreeNode(val));
            }
            else
            {
                add_node(root.get(), num);
            }
        }
    }

    bool add_node(TreeNode *cur_node, int val)
    {
        if (!cur_node)
        {
            return false;
        }

        if (val < cur_node->val)
        {
            auto left_tree = add_node(cur_node->left.get(), val);
            if (!left_tree)
            {
                cur_node->left = std::make_unique<TreeNode>(TreeNode(val));
                std::cout << cur_node->left->val << "\n";
                return true;
            }
        }
        else
        {
            auto right_tree = add_node(cur_node->right.get(), val);
            if (!right_tree)
            {
                cur_node->right = std::make_unique<TreeNode>(TreeNode(val));
                std::cout << cur_node->right->val << "\n";
                return true;
            }
        }
        return false;
    }
};

int main()
{
    // Trie my_trie = Trie({"yo", "mama"});

    // my_trie.add_words_from_txt_file("../words.txt");

    // auto words = my_trie.get_words();
    // for (auto word : words)
    // {
    //     std::cout << word << '\n';
    // }

    BinarySearchTree tree = BinarySearchTree(5, {2, 10, 3, 5});

    return 0;
}
