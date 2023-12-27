#include "trie.hpp"
#include <iostream>

int main()
{
    Trie my_trie = Trie({"yo", "mama"});

    my_trie.add_words_from_txt_file("../words.txt");

    auto words = my_trie.get_words();
    for (auto word : words)
    {
        std::cout << word << '\n';
    }

    return 0;
}
