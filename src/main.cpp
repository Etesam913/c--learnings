#include "trie.hpp"
#include <iostream>

int main()
{
    Trie my_trie = Trie({"yo", "mama"});
    std::cout << my_trie.contains_word("yo");
    my_trie.remove_word("bobby");
    return 0;
}
