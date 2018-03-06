#pragma once

#ifndef _IGRAPH_HPP_
# define _IGRAPH_HPP_

#include <iostream>
#include "Data.hpp"

#define HEIGHT 1500
#define WIDTH 900

class IGraph
{
public:
	virtual ~IGraph() {}
	virtual void PrintExplosion(int x, int y) = 0;
	virtual void PrintSprite(int x, int y, int index) = 0;
	virtual void PrintText(std::string text, int x, int y, int size, bool focus) = 0;
	virtual void Display() = 0;
	virtual void Clear() = 0;
	virtual void StarField() = 0;
	virtual bool IsOpen() = 0;
	virtual void SetInput(Keys &, std::string &, std::string &, bool, bool) = 0;
	virtual void PlaySound(Sounds &) = 0;
	virtual void Close() = 0;
};

#endif