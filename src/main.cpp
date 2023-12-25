#include "trie.hpp"
#include <iostream>


int main()
{
    Trie my_trie = Trie({"yo", "mama"});
    std::cout << my_trie.has_prefix("ma");

	return 0;
}
