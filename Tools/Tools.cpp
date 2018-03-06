#include "Tools.hpp"

Tools::Tools()
{
	
}

void Tools::init(std::vector<Player> &Players,
				 std::vector<std::pair<int, int>> &Fires, std::vector<Player> &Enemy)
{
	players = Players;
	fires = Fires;
	enemies = Enemy;
	ip = "127.0.0.1";
	port = "4242";
	pos = -1;
	connect = false;
	keys = {false, false, false, false, false, false, false, false};
	start = false;
}

	
Keys									&Tools::getKeys()
{
	return (keys);
}

Sounds									&Tools::getSounds()
{
	return (sounds);
}

std::vector<Player>						&Tools::getPlayers()
{
	return (players);
}

std::vector<std::pair<int, int>>		&Tools::getFires()
{
	return (fires);
}

std::vector<Player>		&Tools::getEnemies()
{
	return (enemies);
}

std::string						&Tools::getIp()
{
	return (ip);
}

std::string						&Tools::getPort()
{
	return (port);
}

void									Tools::setIp(const std::string &Ip)
{
	ip = Ip;
}

void									Tools::setPort(const std::string &Port)
{
	port = Port;
}

const int								&Tools::getPos()
{
	return (pos);
}

void									Tools::setPos(const int &Pos)
{
	pos = Pos;
}

const bool								&Tools::getConnect()
{
	return (connect);
}

void									Tools::setConnect(const bool &Connect)
{
	connect = Connect;
}

const bool								&Tools::getStart()
{
	return (start);
}

void									Tools::setStart(const bool &Start)
{
	start = Start;
}

const bool								&Tools::getIpText()
{
	return (ipText);
}

void									Tools::setIpText(const bool &IpText)
{
 ipText = IpText;
}

const bool								&Tools::getPortText()
{
	return (portText);
}

void									Tools::setPortText(const bool &PortText)
{
	portText = PortText;
}
