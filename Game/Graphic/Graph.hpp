#pragma once

#ifndef _GRAPH_HPP
#define _GRAPH_HPP

#include <memory>
#include <iostream>
#include <ctime>
#ifdef _WIN32
#define _WIN32
#include <direct.h>
#endif
#include <string>
#include "Player.hpp"
#include "AState.hpp"
#include "StartState.hpp"
#include "IGraph.hpp"
#include "IModule.hpp"


#define HEIGHT 1500
#define WIDTH 900

//public std::enable_shared_from_this<Graph>

class Graph : public IModule 
{
	enum Key {
		KNONE = 0,
		KANY,
		KUP,
		KDOWN,
		KLEFT,
		KRIGHT,
		KPAUSE,
		KENTER,
		KQUIT
	};

public:
	Graph(Tools&);
	virtual ~Graph() {}
	
	virtual void Exec();
	void SetState(std::shared_ptr<AState>);
	double getVal() {return (d);}
private:
	Tools				&tools;
	double				d;
	std::shared_ptr<AState>			current;
	std::vector<Player>				players;
	std::vector<Player>				Enemy;
	std::vector<std::pair<int, int>> Fires;
};

#endif /* */
