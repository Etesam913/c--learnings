#include <gtest/gtest.h>
#include "trie.hpp"

TEST(Trie, adds_words)
{

    Trie my_trie = Trie({"we", "apple", "banana", "eagle"});
    std::set<std::string> trie_words = my_trie.get_words();

    EXPECT_TRUE(trie_words.find("we") != trie_words.end());
    EXPECT_TRUE(trie_words.find("apple") != trie_words.end());
    EXPECT_TRUE(trie_words.find("banana") != trie_words.end());
    EXPECT_TRUE(trie_words.find("eagle") != trie_words.end());
}

TEST(Trie, remove_words)
{
    Trie my_trie = Trie({"we", "apple", "banana", "eagle"});
    my_trie.remove_word("we");
    my_trie.remove_word("banana");
    std::set<std::string> trie_words = my_trie.get_words();
    EXPECT_ANY_THROW(my_trie.remove_word("joe"));
    EXPECT_TRUE(trie_words.find("we") == trie_words.end());
    EXPECT_TRUE(trie_words.find("apple") != trie_words.end());
    EXPECT_TRUE(trie_words.find("banana") == trie_words.end());
    EXPECT_TRUE(trie_words.find("eagle") != trie_words.end());
}

TEST(trie, contains_words)
{
    Trie my_trie = Trie({"we", "apple", "banana", "eagle"});

    EXPECT_TRUE(my_trie.contains_word("banana"));
    EXPECT_TRUE(my_trie.contains_word("eagle"));
    EXPECT_TRUE(my_trie.contains_word("banana"));
    EXPECT_TRUE(my_trie.contains_word("we"));
    my_trie.remove_word("we");
    EXPECT_FALSE(my_trie.contains_word("we"));
}

TEST(trie, has_word)
{
    Trie my_trie = Trie({"we", "apple", "banana", "eagle"});

    EXPECT_TRUE(my_trie.has_prefix("ban"));
    EXPECT_TRUE(my_trie.has_prefix("eag"));
    EXPECT_FALSE(my_trie.has_prefix("appe"));
    EXPECT_FALSE(my_trie.has_prefix("weee"));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
