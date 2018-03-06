#include "LobbyState.hpp"

LobbyState::LobbyState(Tools &_tools) : tools(_tools)
{
	pos = 0;
	tools.setConnect(false);
	tools.getKeys() = { false, false, false, false, false, false, false, false };
}

void LobbyState::print()
{
	int width = -400;
	int i = 0;
	std::string text;
	tools.lib->PrintText("LOBBY", 0, width, 100, false);
	tools.lib->PrintText("IP: ", -250, width + 150, 50, pos == 0 ? true : false);
	tools.lib->PrintText(tools.getIp(), 50, width + 150, 50, false);
	tools.lib->PrintText("PORT:", -305, width + 250, 50, pos == 1 ? true : false);
	tools.lib->PrintText(tools.getPort(), 50, width + 250, 50, false);

	if (tools.getConnect() == false)
	{
		tools.lib->PrintText("Press Enter to connect", 0, 400, 70, false);
		if (tools.getKeys().KENTER == true)
			tools.setConnect(true);
	}
	else
	{
		width += 250;
		for (auto it : tools.getPlayers())
		{
			width += 100;
			if (tools.getPos() == it.id)
			{
				tools.lib->PrintText("Your are the player " + std::to_string(it.id + 1), -100, width, 50, false);
				tools.lib->PrintText("Ready", 500, width, 50, it.ready == false ? false : true);
			}
			else
			{
				tools.lib->PrintText("Player " + std::to_string(it.id + 1), 0, width, 50, false);
				tools.lib->PrintText("Ready", 500, width, 50, it.ready == false ? false : true);
			}
			++i;
		}
		tools.lib->PrintText("Press Enter to start game", 0, 400, 70, false);
		
		if (tools.getKeys().KENTER == true)
		{
			if (tools.getPos() == -1)
			{
				tools.lib->Close();
				std::cout << "CONNECTION FAIL RESTART THE GAME !!!!" << std::endl;
			}
			else
				tools.getPlayers()[tools.getPos()].ready = true;
		}
	}
}

void LobbyState::input(Graph *graph)
{
	if (tools.getKeys().KQUIT == true)
		tools.lib->Close();
	else if (tools.getKeys().KDOWN == true)
		pos = pos == 1 ? pos = 0 : pos + 1;
	else if (tools.getKeys().KUP == true)
		pos = pos == 0 ? pos = 1 : pos - 1;
	else if (tools.getKeys().KESC == true)
	{
		tools.getSounds().NON = true;
		tools.getSounds().MENU = true;
		graph->SetState(std::make_shared<MenuState>(tools));
	}
	else if (tools.getStart() == true)
	{
		tools.getSounds().VODY = true;
		tools.getSounds().GAME = true;
		graph->SetState(std::make_shared<GameState>(tools));
	}
	if (pos == 0)
	{
		tools.setIpText(true);
		tools.setPortText(false);
	}
	else if (pos == 1)
	{
		tools.setIpText(false);
		tools.setPortText(true);
	}
}
