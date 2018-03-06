#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include <memory>
#include <iostream>
#include <boost/asio/ip/udp.hpp>
#include "Game.hpp"
#include "Shared.h"
#include "Protocol.h"
#include "Player.hpp"
#include "Room.hpp"

class Server 
{
public:
	Server(int port, boost::asio::io_service& _io_service);
	~Server();
private:
	void start_receive();
	void create_player(boost::asio::ip::udp::endpoint);
	void handle_send(int );
	void handleSendAll();
	void fillPlayers();
    void launchGame();
	int freeRoom();
	int freeId(int);
    int getRoom(boost::asio::ip::udp::endpoint);
	bool endPointExist(boost::asio::ip::udp::endpoint endpoint);
    int port;
    boost::asio::ip::udp::socket _socket;
	boost::asio::ip::udp::endpoint _remote_endpoint;
	t_proto proto;
	std::vector<std::shared_ptr<Room>> rooms;
    boost::asio::io_service &io_service;
};

#endif
