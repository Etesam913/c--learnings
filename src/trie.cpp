#include "trie.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <boost/algorithm/string.hpp>

TrieNode::TrieNode() = default;

TrieNode::TrieNode(char letter, bool is_word_val = false) {
    TrieNode::cur_char = letter;
    TrieNode::is_word = is_word_val;
}

Trie::Trie(const std::vector<std::string> passed_in_words) {
    root = std::make_shared<TrieNode>();
    words = std::make_unique<std::set<std::string>>();
    for (std::string word: passed_in_words) {

        add_word(word);
    }
}

bool Trie::contains_word(const std::string &word) {
    std::shared_ptr<TrieNode> curNode = root;
    for (auto c: word) {
        if (curNode->children.count(c)) {
            curNode = curNode->children[c];
        } else {
            return false;
        }
    }
    return curNode->is_word;
}

bool Trie::has_prefix(const std::string &word) {
    std::shared_ptr<TrieNode> curNode = root;
    for (auto c: word) {
        if (curNode->children.count(c)) {
            curNode = curNode->children[c];
        } else {
            return false;
        }
    }
    return true;
}

void Trie::add_word(const std::string &word) {
    words->insert(word);
    std::shared_ptr<TrieNode> curNode = root;
    for (char ch: word) {
        if (curNode->children.count(ch)) {
            curNode = curNode->children[ch];
            curNode->prefix_count += 1;
        } else {
            auto newNode = std::make_shared<TrieNode>(ch);
            curNode->children[ch] = newNode;
            curNode = newNode;
        }
    }
    curNode->is_word = true;
}

void Trie::add_words_from_txt_file(const std::string &file_path) {
    std::ifstream file_stream(file_path);
    if (!file_stream.is_open()) {
        throw std::invalid_argument(file_path + " cannot be opened.");
    }

    std::string line;
    while (getline(file_stream, line)) {
        std::string separator = ",";
        std::vector<std::string> words = {};
        boost::split(words, line, boost::is_any_of(","));
        for (auto word: words) {
            boost::trim(word);
            add_word(word);
        }
    }
}

void Trie::remove_word(const std::string &word) {
    words->erase(word);
    std::shared_ptr<TrieNode> curNode = root;
    std::vector<std::shared_ptr<TrieNode>> nodePath{};
    // Loop until you reach the last node of the Trie
    for (char ch: word) {
        if (curNode->children.count(ch)) {
            std::shared_ptr<TrieNode> childNode = curNode->children[ch];
            curNode = childNode;
            nodePath.push_back(curNode);
        } else {
            throw std::invalid_argument("This word does not exist");
            return;
        }
    }
    // If the last node is not a word, nothing can't be removed.
    if (!curNode->is_word) {
        throw std::invalid_argument("This word does not exist");
        return;
    }
        /*
          Loop through all the nodes and reduce their prefix count by 1
          If the prefix count becomes 0 that means that the node is not
          used by any other word and can then be removed.
        */
    else {
        std::shared_ptr<TrieNode> prevNode{root};
        for (auto node: nodePath) {
            node->prefix_count -= 1;
            if (node->prefix_count == 0) {

                prevNode->children.erase(node->cur_char);

                node.reset();
                return;
            }
            prevNode = node;
        }
    }
}

std::set<std::string> Trie::get_words() {
    return *words;
}
