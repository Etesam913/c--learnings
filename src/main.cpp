
#include "trie.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

int main()
{

	Trie myTrie{Trie({"Apple", "Joe", "Mama"})};
	// std::cout << myTrie.contains_word("Mama") << "\n"
	// 					<< myTrie.has_prefix("App") << "\n"
	// 					<< myTrie.has_prefix("Abb");

	// myTrie.remove_word("Apple");
	// std::cout << myTrie.has_prefix("App");
	return 0;
}
