#include <memory>

struct TreeNode
{
  int val{0};
  std::unique_ptr<TreeNode> left{};
  std::unique_ptr<TreeNode> right{};

  TreeNode(const int startVal);
};

class BinarySearchTree
{
private:
  std::unique_ptr<TreeNode> root{};

public:
  BinarySearchTree(const std::vector<int> nodes);

  bool add_node(int val);

  std::vector<TreeNode *> get_inorder_traversal();
};
