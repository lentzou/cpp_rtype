#pragma once

#ifndef _GAMESTATE_HPP_
# define _GAMESTATE_HPP_

#include "LobbyState.hpp"

class GameState : public AState
{
public:
	GameState(Tools &Tools);
	virtual ~GameState() {}
	virtual void	print();
	virtual void	input(Graph *);
	void checkCollision();
	void createEnemy();
	void printEnemies();
	void printPlayers();
	void printFires();
private:
	double 		val;
	Tools		&tools;
	clock_t		coolDown;
};

#endif
