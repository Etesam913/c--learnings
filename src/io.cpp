#include <iostream>
#include "trie.h"
#include "io.h"
#include <ftxui/component/component.hpp>

void display_trie(ftxui::ScreenInteractive &screen, ftxui::Component &renderer, ftxui::MenuOption &option_obj)
{
  using namespace ftxui;
  screen.Clear();
  int selected_entry = 0;
  std::vector<std::string> trie_data_options = {"Add words yourself", "Load words from an api"};
  auto menu = Menu(&trie_data_options, &selected_entry, option_obj);
  renderer = Renderer(menu, [&]
                      { return vbox({text("Choose a data structure:") | border, menu->Render() | frame}); });

  screen.Loop(renderer);
  std::vector<std::string> words = {};
  // Add words yourself
  if (selected_entry == 0)
  {
    std::cout << "Write the words that you want to add and separate them with a new line\n";

    std::string input = "";
    while (std::getline(std::cin, input))
    {
      if (input.empty())
      {
        break;
      }
      words.emplace_back(input);
    }
    std::cout << "\n";
    Trie constructedTrie = Trie(words);
  }
  else
  {
  }
  std::vector<Element> words_as_ftx_text = {text("You added the below words to your trie:") | border};

  for (std::string s : words)
  {
    words_as_ftx_text.emplace_back(text("* " + s));
  }

  selected_entry = 0;
  std::vector<std::string> trie_methods = {"contains_word", "has_prefix", "add_word", "remove_word"};
  menu = Menu(&trie_methods, &selected_entry, option_obj);

  renderer = Renderer(menu, [&]
                      { return vbox({text("Trie created successfully!") | border | color(Color::Green3), vbox(words_as_ftx_text), text("Choose a function to run:") | border, menu->Render()}); });
  screen.Loop(renderer);
};
