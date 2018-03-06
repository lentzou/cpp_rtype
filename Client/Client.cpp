//
// Created by ant paute on 27/01/2018.
//

#include <string>
#include "Client.hpp"
#include "Network.hpp"
#include "Tools.hpp"

Client::Client (boost::asio::io_service& io_service, std::string Ip, std::string Port, int id) : socket_(io_service), resolver_(io_service), ip(Ip), port(Port), _io_service(io_service)
{
	this->id = id;
    tryConnection();
}

Client::~Client()
{

}

void Client::checkTools()
{
	Tools &tools = Tools::Instance();
	tools.dead = false;
	tools.ennemy = -1;
	while (tools.dead == false)
	{
		if (tools.getKeys().KUP == true)
			goUp();
		if (tools.getKeys().KDOWN == true)
			goDown();
		if (tools.getKeys().KRIGHT == true)
			goRight();
		if (tools.getKeys().KLEFT == true)
			goLeft();
		if (tools.fire == true)
			goSpace();
		if (tools.getKeys().KENEMY == true)
			goEnnemy();
		if (tools.ennemy >= 0)
			goErase();
	}
}

void Client::goRight()
{
	Tools &tools = Tools::Instance();
	tools.getKeys().KRIGHT = false;
	proto.state = 302;
	proto.id = id;
	HandleSend();
}

void Client::goLeft()
{
	Tools &tools = Tools::Instance();
	tools.getKeys().KLEFT = false;
	proto.state = 303;
	proto.id = id;
	HandleSend();
}

void Client::goDown()
{
	Tools &tools = Tools::Instance();
	tools.getKeys().KDOWN = false;
	proto.state = 304;
	proto.id = id;
	HandleSend();
}

void Client::goUp()
{
	Tools &tools = Tools::Instance();
	tools.getKeys().KUP = false;
	proto.state = 305;
	proto.id = id;
	HandleSend();
}

void Client::goSpace()
{
	Tools &tools = Tools::Instance();
	tools.fire = false;	
	proto.state = 306;
	proto.id = id;
	HandleSend();
}

void Client::goEnnemy()
{
	Tools &tools = Tools::Instance();
	tools.getKeys().KENEMY = false;
	proto.state = 307;
	HandleSend();
}

void Client::goErase()
{
	Tools &tools = Tools::Instance();

	proto.state = 308;
	proto.id = tools.ennemy;
	tools.ennemy = -1;
	HandleSend();
}
void Client::goDead()
{
	Tools &tools = Tools::Instance();
	if (id == tools.dead)
	{
		dead = true;
		//tools.dead = -1;
		//proto.state = 309;
		//HandleSend();
		//tools.lib->Close();
		//exit(0);
	}
}

void Client::receiverServer()
{
    while (1) 
	{
        socket_.receive_from(boost::asio::buffer(&proto, sizeof(proto)), endpoint);
        this->proto = proto;
        checkAll();
    }
}

void Client::checkAll()
{
	Tools &tools = Tools::Instance();

	switch (proto.state)
	{
	case 301:
		// Start
		tools.setStart(true);
		break;
	case 302:
		//Droite
		tools.getPlayers()[proto.id].x = proto.x;
		break;

	case 303:
		//Gauche
		tools.getPlayers()[proto.id].x = proto.x;
		break;
	case 304:
		//Bas
		tools.getPlayers()[proto.id].y = proto.y;
		break;
	case 305:
		//Haut
		tools.getPlayers()[proto.id].y = proto.y;
		break;
	case 306:
		// Feu
		tools.getPlayers()[proto.id].fire = true;
		tools.getSounds().FIRE = true;
		break;
	case 307:
	{
		// Ennemies
		Player t(0);
		t.x = proto.x;
		t.y = proto.y;
		tools.getSounds().PORTE = true;
		tools.getEnemies().push_back(t);
		break;
	}
	case 308:
		// Mort ennemies
		tools.enemies.erase(tools.enemies.begin() + proto.id);
		break;
	case 309:
		// Mort joueur
		tools.players.erase(tools.players.begin() + proto.id);
		break;
	}
}

void Client::tryConnection()
{
    try
    {
        boost::asio::ip::udp::resolver::query query(udp::v4(), ip, port);
        boost::asio::ip::udp::endpoint receiver_endpoint = *resolver_.resolve(query);
        socket_.open(udp::v4());
        proto.state = 301;
		proto.id = id;
        socket_.send_to(boost::asio::buffer(&proto, sizeof(proto)), receiver_endpoint);
        endpoint = receiver_endpoint;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return ;
}

void Client::HandleSend()
{
    socket_.send_to(boost::asio::buffer(&proto, sizeof(proto)), endpoint);
}

