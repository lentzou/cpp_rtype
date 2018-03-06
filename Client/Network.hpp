#pragma once

#ifndef _NETWORK_HPP
#define _NETWORK_HPP

#include <iostream>
#include "Protocol.h"
#include "../Common/Player.hpp"

using boost::asio::ip::udp;

class Network
{
public:
	Network(boost::asio::io_service& io_service, std::string, std::string);
	~Network();
	void tryConnection();
	void receiverServer();
	void HandleSend();
	void checkAll();
	void checkTools();
	std::string port;
	std::string ip;
	int id;
private:
	t_proto proto;
	boost::asio::ip::udp::socket socket_;
	boost::asio::ip::udp::resolver resolver_;
	boost::asio::ip::udp::endpoint endpoint;
	std::vector<Player> players;
	boost::asio::io_service& _io_service;
	bool startChecking = false;
	bool leave = false;
};

#endif /* */
