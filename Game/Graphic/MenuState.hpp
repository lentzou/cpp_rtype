#pragma once

#ifndef _MENUSTATE_HPP_
# define _MENUSTATE_HPP_

#include "StartState.hpp"
#include "CreditState.hpp"
#include "LobbyState.hpp"

class MenuState : public AState
{
public:
	MenuState(Tools &Tools);
	virtual ~MenuState() {}
	virtual void	print();
	virtual void	input(Graph *);
private:
	Tools		&tools;
	int			pos;
};

#endif
