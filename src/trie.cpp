#include "trie.h"
#include <iostream>
#include <unordered_map>
#include <vector>

TrieNode::TrieNode(){

};

TrieNode::TrieNode(char letter, bool is_word_val = false)
{
  TrieNode::cur_char = letter;
  TrieNode::is_word = is_word_val;
};

Trie::Trie(const std::vector<std::string> &words)
{
  root = std::make_shared<TrieNode>();
  for (auto word : words)
  {
    add_word(word);
  }
}

bool Trie::contains_word(const std::string &word)
{
  std::shared_ptr<TrieNode> curNode = root;
  for (auto c : word)
  {
    if (curNode->children.count(c))
    {
      curNode = curNode->children[c];
    }
    else
    {
      return false;
    }
  }
  return curNode->is_word;
};

bool Trie::has_prefix(const std::string &word)
{
  std::shared_ptr<TrieNode> curNode = root;
  for (auto c : word)
  {
    if (curNode->children.count(c))
    {
      curNode = curNode->children[c];
    }
    else
    {
      return false;
    }
  }
  return true;
};

void Trie::add_word(const std::string &word)
{
  std::shared_ptr<TrieNode> curNode = root;
  for (char ch : word)
  {
    if (curNode->children.count(ch))
    {
      curNode = curNode->children[ch];
      curNode->prefix_count += 1;
    }
    else
    {
      auto newNode = std::make_shared<TrieNode>(ch);
      curNode->children[ch] = newNode;
      curNode = newNode;
    }
  }
  curNode->is_word = true;
};

void Trie::remove_word(const std::string &word)
{
  std::shared_ptr<TrieNode> curNode = root;
  std::vector<std::shared_ptr<TrieNode>> nodePath{};
  // Loop until you reach the last node of the Trie
  for (char ch : word)
  {
    if (curNode->children.count(ch))
    {
      std::shared_ptr<TrieNode> childNode = curNode->children[ch];
      curNode = childNode;
      nodePath.push_back(curNode);
    }
    else
    {
      std::cout << "The word does not exist \n";
      return;
    }
  }
  // If the last node is not a word, nothing can't be removed.
  if (!curNode->is_word)
  {
    std::cout << "The word does not exist \n";
    return;
  }
  /*
    Loop through all the nodes and reduce their prefix count by 1
    If the prefix count becomes 0 that means that the node is not
    used by any other word and can then be removed.
  */
  else
  {
    std::shared_ptr<TrieNode> prevNode{root};
    for (auto node : nodePath)
    {
      node->prefix_count -= 1;
      if (node->prefix_count == 0)
      {

        prevNode->children.erase(node->cur_char);

        node.reset();
        return;
      }
      prevNode = node;
    }
  }
}
