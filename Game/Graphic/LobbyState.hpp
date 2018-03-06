#pragma once

#ifndef _LOBBYSTATE_HPP_
# define _LOBBYSTATE_HPP_

#include "MenuState.hpp"
#include "GameState.hpp"

class LobbyState : public AState
{
public:
	LobbyState(Tools &Tools);
	virtual ~LobbyState() {}
	virtual void	print();
	virtual void	input(Graph *);
private:
	Tools		&tools;
	int			pos;
};

#endif
