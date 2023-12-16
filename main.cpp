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

struct TrieNode
{
	bool is_word{false};
	std::unordered_map<char, std::vector<std::string>> children;
};

class Trie
{
private:
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

		std::cout << "Added word: " << word << '\n';
	}
};

int main()
{
	Trie myTrie{Trie({"Apple", "Banana", "Advantageous"})};
	return 0;
}
