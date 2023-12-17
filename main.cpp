/*
	Basic Trie Implementation

	unordered map with char as key and array of char as value

	has_prefix(std::string prefix);
	has_word(std::string word);
	add_word(std::string);
	remove_word(std::string);
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <utility>

struct TrieNode
{
	bool is_word{false};
	std::unordered_map<char, std::shared_ptr<TrieNode>> children;
	char cur_char{};
	int prefix_count{1};

	TrieNode()
	{
	}

	TrieNode(char letter, bool is_word_val = false)
	{
		cur_char = letter;
		is_word = is_word_val;
	}
};

class Trie
{
private:
	std::shared_ptr<TrieNode> root{std::make_shared<TrieNode>(TrieNode())};

public:
	Trie(const std::vector<std::string> &words)
	{
		for (auto word : words)
		{
			add_word(word);
		}
	}

	bool contains_word(const std::string &word)
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
	}

	bool has_prefix(const std::string &word)
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
	}

	void add_word(const std::string &word)
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
	}

	void remove_word(const std::string &word)
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
				std::cout << '(' << node->cur_char << " " << node->prefix_count << " " << node->is_word << "), ";
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
};

int main()
{
	int x = 2;

	Trie myTrie{Trie({"Apple"})};

	myTrie.remove_word("Apple");
	std::cout << myTrie.has_prefix("App");

	return 0;
}
