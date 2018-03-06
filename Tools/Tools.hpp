#ifndef _TOOLS_HPP_
# define _TOOLS_HPP_

#include <iostream>
#include <memory>
#include "Player.hpp"
#include "IGraph.hpp"
#include "Singleton.hpp"


class Tools : public Singleton<Tools>
{
public:
	/*struct Keys{
		bool	KUP;
		bool	KDOWN;
		bool	KLEFT;
		bool	KRIGHT;
		bool	KSPACE;
		bool	KESC;
		bool	KENTER;
		bool	KQUIT;
		bool	KENEMY;
		bool	KANY;
	};

	struct Sounds {
		bool	START;
		bool	MENU;
		bool	LOBBY;
		bool	GAME;
		bool	CREDIT;
		bool	FIRE;
		bool	ENEMY;
		bool	BOSS;
		bool	BONUS;
		bool	EFFECT;
		bool	PORTE;
	};*/

	friend class Singleton<Tools>;
	Tools();
	~Tools() {}
	void									init(std::vector<Player> &,
												 std::vector<std::pair<int, int>> &, std::vector<Player> &);
	Sounds									&getSounds();
	std::vector<Player>						&getPlayers();
	std::vector<std::pair<int, int>>		&getFires();
	std::vector<Player>						&getEnemies();
	std::string								&getIp();
	std::string								&getPort();
	Keys									&getKeys();
	IGraph									*lib;
	

	const int								&getPos();
	const bool								&getPortText();
	const bool								&getIpText();
	const bool								&getConnect();
	const bool								&getStart();
	void									setIp(const std::string &);
	void									setPort(const std::string &);
	void									setPos(const int &Pos);
	void									setConnect(const bool &Connect);
	void									setStart(const bool &start);
	void									setIpText(const bool &);
	void									setPortText(const bool &);
	bool									fire;
	std::vector<std::pair<int, int>>		fires;
	std::vector<Player>						enemies;
	std::vector<Player>						players;
	int										ennemy;
	bool										dead;
private:
	
	std::string								ip;
	std::string								port;
	int										pos;
	bool									connect;
	bool									start;
	bool									ipText;
	bool									portText;
	Keys									keys;
	Sounds									sounds;
};
#endif
