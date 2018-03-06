#include "StartState.hpp"

StartState::StartState(Tools &_tools) : tools(_tools)
{
	tools.getKeys() = { false, false, false, false, false, false, false, false };
	tools.getSounds().START = true;
}

void StartState::print()
{
	clock_t startTime = clock();
	srand((unsigned int)time(NULL));
	tools.lib->PrintText("RTYPE", 0, 0, 100, false);
	if ((((int)startTime / CLOCKS_PER_SEC) % 2) == 0)
		tools.lib->PrintText("Press any key to start or \"esc\" to quit", 0, 100, 20, false);
}


void StartState::input(Graph *graph)
{
	if (tools.getKeys().KQUIT == true || tools.getKeys().KESC == true)
	{
		tools.getSounds().NOPE = true;
		tools.lib->Close();
	}
	else if (tools.getKeys().KANY == true)
	{
		tools.getSounds().OLED = true;
		tools.getSounds().MENU = true;
		graph->SetState(std::make_shared<MenuState>(tools));
	}
}
