#include "GameState.hpp"

GameState::GameState(Tools &_tools) : tools(_tools)
{
	coolDown = clock();
	tools.getKeys() = { false, false, false, false, false, false, false, false };
}

void GameState::printPlayers()
{
	int i = -1;
	for (auto it : tools.getPlayers())
			tools.lib->PrintSprite(it.x, it.y, it.id);
}

void GameState::printFires()
{
    for (std::vector<std::pair<int, int >>::iterator it = tools.getFires().begin(); it !=tools.getFires().end(); it = it)
    {
        if ((*it).first >= HEIGHT - 50)
            it = tools.getFires().erase(it);
        else
        {
            (*it).first += 15;
			tools.lib->PrintSprite((*it).first, (*it).second, 4);
            ++it;
        }
    }
}

void GameState::printEnemies()
{
	for (auto it : tools.getEnemies())
	{
		tools.lib->PrintSprite(it.x, it.y, 5);
	}
}

void GameState::print()
{
	printPlayers();
    printFires();
    printEnemies();
	checkCollision();
}

void GameState::checkCollision()
{
	int i = 0;
	int j = 0;
	for (auto fire : tools.getFires())
	{
		j = 0;
		for (auto player : tools.getPlayers())
		{
			if (fire.first < player.x + 17 &&
				fire.first + 34 > player.x &&
				fire.second < player.y + 15 &&
				18 + fire.second > player.y) {
				tools.getFires().erase(tools.getFires().begin() + i);
			}
		}
		for (auto ennemy : tools.getEnemies())
		{
			if (fire.first < ennemy.x + 75 &&
				fire.first + 17 > ennemy.x &&
				fire.second < ennemy.y + 75 &&
				20 + fire.second > ennemy.y) {
				tools.lib->PrintExplosion(ennemy.x, ennemy.y);
				tools.fires.erase(tools.fires.begin() + i);
				tools.ennemy = j;
			}
			j++;
		}
		i++;
	}
	for (auto player : tools.getPlayers())
	{
		j = 0;
		for (auto ennemy : tools.getEnemies())
		{
			if (player.x < ennemy.x + 75 &&
				player.x + 34 > ennemy.x &&
				player.y < ennemy.y + 75 &&
				18 + player.y > ennemy.y) {
				tools.getEnemies().erase(tools.getEnemies().begin() + j);
				if (player.id == tools.getPos())
					tools.dead = true;
			}
			j++;
		}
	}
	if (tools.dead)
		tools.lib->PrintText("GAME OVER", 0, 0, 100, true);

}

void GameState::input(Graph *graph)
{
	if (tools.getKeys().KQUIT == true)
		tools.lib->Close();
	if (tools.getKeys().KSPACE == true)
	{
		if (((clock() - coolDown) / (double)CLOCKS_PER_SEC) > 0.2)
		{
			tools.fire = true;
			coolDown = clock();
		}
	}
	for (auto player : tools.getPlayers())
	{
		if (player.fire == true)
		{
			tools.getPlayers()[player.id].fire = false;
			tools.getFires().push_back(std::make_pair(player.x + 50, player.y));
		}
	}
	if (tools.getKeys().KESC == true)
	{
		tools.getPlayers()[tools.getPos()].ready = false;
		graph->SetState(std::make_shared<LobbyState>(tools));
	}
}
