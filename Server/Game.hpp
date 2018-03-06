//
// Created by ant paute on 26/01/2018.
//

#ifndef CPP_RTYPE_GAME_HPP
#define CPP_RTYPE_GAME_HPP

#include <thread>
#include <iostream>
#include <boost/asio/ip/udp.hpp>
#include "Player.hpp"
#include "Protocol.h"

class Game {
public:
	Game(int port, boost::asio::io_service& io_service, std::vector<std::shared_ptr<Player>> &players);
	~Game();
private:
	std::vector<std::shared_ptr<Player>> &players;
    t_proto proto;
    boost::asio::ip::udp::socket _socket;
    void start_receive();
    boost::asio::ip::udp::endpoint _remote_endpoint;
	void create_player(boost::asio::ip::udp::endpoint);
    int getId(boost::asio::ip::udp::endpoint);
    boost::asio::io_service &io_service;
	void handle_send(int);
	void handle_all();
};


#endif //CPP_RTYPE_GAME_HPP
