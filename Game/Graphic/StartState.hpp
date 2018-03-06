#pragma once

#ifndef _StartState_HPP_
# define _StartState_HPP_

#include "Graph.hpp"
#include "MenuState.hpp"

class StartState : public AState
{
public:
	StartState(Tools &Tools);
	virtual ~StartState() {}	
	virtual void print();
	virtual void input(Graph *);
private:
	Tools	&tools;
};

#endif
