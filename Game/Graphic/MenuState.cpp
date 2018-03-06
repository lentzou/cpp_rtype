#include "MenuState.hpp"

MenuState::MenuState(Tools &_tools) : tools(_tools)
{
	pos = 0;
	tools.getKeys() = { false, false, false, false, false, false, false, false };
}

void MenuState::print()
{
	tools.lib->PrintText("PLAY", 0, -300, 100, pos == 0 ? true : false);
	tools.lib->PrintText("CREDIT", 0, -100, 100, pos == 1 ? true : false);
	tools.lib->PrintText("QUIT", 0, 100, 100, pos == 2 ? true : false);
}

void MenuState::input(Graph *graph)
{
	if (tools.getKeys().KQUIT == true)
		tools.lib->Close();
	else if (tools.getKeys().KDOWN == true)
		pos = pos == 2 ? pos = 0 : pos + 1;
	else if (tools.getKeys().KUP == true)
		pos = pos == 0 ? pos = 2 : pos - 1;
	else if (tools.getKeys().KENTER == true)
	{
		if (pos == 0)
		{
			tools.getSounds().OUI = true;
			tools.getSounds().LOBBY = true;
			graph->SetState(std::make_shared<LobbyState>(tools));
		}
		else if (pos == 1)
		{
			tools.getSounds().VODY = true;
			tools.getSounds().CREDIT = true;
			graph->SetState(std::make_shared<CreditState>(tools));
		}
		else if (pos == 2)
			tools.lib->Close();
	}
	else if (tools.getKeys().KESC == true)
	{
		tools.getSounds().NON = true;
		tools.getSounds().START = true;
		graph->SetState(std::make_shared<StartState>(tools));
	}
}
