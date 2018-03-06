#pragma once
#ifndef _AState_HPP_
# define _AState_HPP_

#include "Tools.hpp"
#include <iostream>

#define HEIGHT 1500
#define WIDTH 900

class Graph;

class AState
{
public:
	virtual ~AState() {}
	virtual void print() = 0;
	virtual void input(Graph *) = 0;
};

#endif
