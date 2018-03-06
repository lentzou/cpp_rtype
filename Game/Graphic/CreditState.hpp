#pragma once

#ifndef _CREDITSTATE_HPP_
# define _CREDITSTATE_HPP_

#include "MenuState.hpp"

class CreditState : public AState
{
public:
	CreditState(Tools &Tools);
	virtual ~CreditState() {}
	virtual void	print();
	virtual void	input(Graph *);
private:
	Tools		&tools;
};

#endif
