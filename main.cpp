
#include "trie.h"
#include <iostream>

int main()
{
	int x = 2;

	Trie myTrie{Trie({"Apple", "Joe", "Mama"})};
	std::cout << myTrie.contains_word("Mama") << "\n"
						<< myTrie.has_prefix("App") << "\n"
						<< myTrie.has_prefix("Abb");

	myTrie.remove_word("Apple");
	std::cout << myTrie.has_prefix("App");

	return 0;
}
