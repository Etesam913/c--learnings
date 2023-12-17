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
	std::unordered_map<char, std::unique_ptr<TrieNode>> children;
	char cur_char{};

	TrieNode()
	{
	}

	TrieNode(char letter, bool is_word_val = false)
	{
		cur_char = letter;
		is_word = is_word_val;
		std::cout << cur_char << '\n';
	}
};

class Trie
{
private:
	std::unique_ptr<TrieNode> root = std::make_unique<TrieNode>(TrieNode());

public:
	Trie(std::vector<std::string> words)
	{
		for (auto word : words)
		{
			add_word(word);
		}
	}

	void add_word(std::string word)
	{
		auto curNode = root.get();
		for (char ch : word)
		{
			if (curNode->children.count(ch))
			{
				curNode = curNode->children[ch].get();
			}
			else
			{
				curNode->children[ch] = std::make_unique<TrieNode>(ch);
				curNode = curNode->children[ch].get();
			}
		}
		curNode->is_word = true;
	}
};

int main()
{
	Trie myTrie{Trie({"Apple", "Banana", "Advantageous"})};
	return 0;
}
