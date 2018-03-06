#include <boost/asio/detail/posix_thread.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/udp.hpp>
#include <thread>
#include "Network.hpp"
#include "Client.hpp"
#include "Tools.hpp"

Network::Network(boost::asio::io_service& io_service, std::string Ip, std::string Port) 
	: socket_(io_service), resolver_(io_service), ip(Ip), port(Port), _io_service(io_service)
{
	tryConnection();
}

Network::~Network()
{
}

void Network::checkTools()
{
	Tools &tools = Tools::Instance();
	bool alreadyLentz = false;
	while (1)
	{
		if (startChecking == true)
		{
			if (tools.getPlayers()[id].ready == true && alreadyLentz == false)
			{
				proto.state = 201;
				proto.id = id;
				HandleSend();
				alreadyLentz = true;
			}
		}
		if (leave == true)
			return;
	}
}

void Network::receiverServer() 
{
	try
	{
		while (1)
		{			
			socket_.receive_from(boost::asio::buffer(&proto, sizeof(proto)), endpoint);
			this->proto = proto;
			checkAll();
			if (leave == true)
				return;
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Network::checkAll()
{
	Tools &tools = Tools::Instance();

	switch (proto.state)
	{
	case 101:
	{
		Player tmp(proto.id);
		tmp.x = proto.x;
		tmp.y = proto.y;
		tmp.ready = proto.ready;
		id = proto.id;
		tools.getPlayers().push_back(tmp);
		tools.setPos(id);
		proto.state = 0;
		HandleSend();
		startChecking = true;
		break;
	}
	case 102:
	{
		Player tmp(proto.id);
		tmp.x = proto.x;
		tmp.y = proto.y;
		tmp.ready = proto.ready;
		tools.getPlayers().push_back(tmp);
		break;
	}
	case 103:
	{
		Player tmp(proto.id);
		tmp.x = proto.x;
		tmp.y = proto.y;
		tmp.ready = proto.ready;
		tools.getPlayers().push_back(tmp);
		break;
	}
	case 201:
		tools.getPlayers()[proto.id].ready = true;
		break;
	case 202:
		leave = true;
		port = std::to_string(proto.port);
		break;
	case 203:
		proto.state = 0;
		HandleSend();
		break;
	}
}

void Network::tryConnection()
{
	try
	{
		boost::asio::ip::udp::resolver::query query(udp::v4(), ip, port);
		boost::asio::ip::udp::endpoint receiver_endpoint = *resolver_.resolve(query);
		socket_.open(udp::v4());
        proto.state = 101;
		socket_.send_to(boost::asio::buffer(&proto, sizeof(proto)), receiver_endpoint);
		endpoint = receiver_endpoint;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ;
}

void Network::HandleSend()
{
	socket_.send_to(boost::asio::buffer(&proto, sizeof(proto)), endpoint);
}

