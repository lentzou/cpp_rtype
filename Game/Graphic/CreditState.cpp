#include "CreditState.hpp"

CreditState::CreditState(Tools &_tools) : tools(_tools)
{
	tools.getKeys() = { false, false, false, false, false, false, false, false };
}

void CreditState::print()
{
	clock_t startTime = clock();
	srand((unsigned int)time(NULL));

	tools.lib->PrintText("Game created by:", 0, -400, 100, false);
	tools.lib->PrintText("Antoine Paute", 0, -200, 30, false);
	tools.lib->PrintText("Corentin Bellamy", 0, -100, 30, false);
	tools.lib->PrintText("Florian Lentz", 0, 0, 30, false);
	tools.lib->PrintText("Phillipe Xu", 0, 100, 30, false);
	tools.lib->PrintText("Stéphane Nagamouttou", 0, 200, 30, false);
	tools.lib->PrintText("Yoann Wargnier", 0, 300, 30, false);

	if ((((int)startTime / CLOCKS_PER_SEC) % 2) == 0)
		tools.lib->PrintText("Press any key to back", 0, 400, 30, false);
}

void CreditState::input(Graph *graph)
{
	if (tools.getKeys().KANY == true)
	{
		tools.getSounds().MENU = true;
		graph->SetState(std::make_shared<MenuState>(tools));
	}
	else if (tools.getKeys().KQUIT == true)
		tools.lib->Close();
}
