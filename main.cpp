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
			}
			else
			{
				curNode->children[ch] = std::make_shared<TrieNode>(ch);
				curNode->cur_char = ch;
				curNode = curNode->children[ch];
			}
		}
		curNode->is_word = true;
	}
};

int main()
{
	int x = 2;
	int &xRef = x;

	Trie myTrie{Trie({"Apple", "Banana", "Advantageous"})};
	std::cout << myTrie.contains_word("Banana") << '\n'
						<< myTrie.contains_word("Ad") << '\n'
						<< myTrie.has_prefix("Ad") << '\n';

	xRef = 5;

	std::cout << xRef << x;
	return 0;
}
