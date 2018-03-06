//
// Created by ant paute on 27/01/2018.
//

#ifndef CPP_RTYPE_CLIENT_HPP
#define CPP_RTYPE_CLIENT_HPP

#include <thread>
#include <boost/asio/io_service.hpp>
#include <Player.hpp>
#include <Protocol.h>

class Client {
public :
    Client(boost::asio::io_service& io_service, std::string, std::string, int id);
    ~Client();
    void tryConnection();
    void receiverServer();
    void HandleSend();
    void checkAll();
	void checkTools();
	void goUp();
	void goDown();
	void goLeft();
	void goRight();
	void goSpace();
	void goEnnemy();
	void goErase();
	void goDead();

	bool dead;
	std::thread t1;
    t_proto proto;
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::resolver resolver_;
    boost::asio::ip::udp::endpoint endpoint;
    std::string ip;
    std::string port;
    std::vector<Player> players;
	boost::asio::io_service& _io_service;
    int id;
};



#endif //CPP_RTYPE_CLIENT_HPP
