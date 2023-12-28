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

TEST(trie, add_words_from_txt_file)
{
    Trie my_trie = Trie({});
    my_trie.add_words_from_txt_file("../words.txt");
    auto trie_words = my_trie.get_words();
    EXPECT_TRUE(trie_words.find("joe") != trie_words.end());
    EXPECT_TRUE(trie_words.find("yolo") != trie_words.end());
    EXPECT_TRUE(trie_words.find("mama") != trie_words.end());
    EXPECT_TRUE(trie_words.find("is") != trie_words.end());
    EXPECT_TRUE(trie_words.find("cool") != trie_words.end());
    EXPECT_TRUE(trie_words.find("ok") != trie_words.end());
    EXPECT_TRUE(trie_words.find("dude") != trie_words.end());
    EXPECT_TRUE(trie_words.find("etesam") != trie_words.end());
    EXPECT_TRUE(trie_words.find("was") != trie_words.end());
    EXPECT_TRUE(trie_words.find("here") != trie_words.end());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
