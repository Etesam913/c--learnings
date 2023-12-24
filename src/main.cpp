#include "ftxui/component/screen_interactive.hpp" // for ScreenInteractive
#include <ftxui/component/component.hpp>
#include "io.h"
#include "utility.h"
#include <iostream>
int main()
{
	using namespace ftxui;
	std::vector<std::string> data_structure_entries = {"Trie", "LRU Cache (not yet implemented)"};
	auto screen = ScreenInteractive::TerminalOutput();

	// Create MenuOption obj
	MenuOption option_obj;
	option_obj.on_enter = screen.ExitLoopClosure();
	int selected_entry = 0;

	// Create Menu
	auto menu = Menu(&data_structure_entries, &selected_entry, option_obj);

	// Create Renderer to display content
	auto renderer = Renderer(menu, [&]
													 { return vbox({text("Choose a data structure:") | border, menu->Render()}); });

	screen.Loop(renderer);

	if (data_structure_entries[selected_entry].find("(not yet implemented)") != std::string::npos)
	{
		std::cout << "This data structure is not yet implemented\n";
		return 0;
	}

	else if (data_structure_entries[selected_entry] == "Trie")
	{
		display_trie(screen, renderer, option_obj);
	}

	return 0;
}
