//
// Created by ant paute on 25/01/2018.
//

#ifndef CPP_RTYPE_ROOM_HPP
#define CPP_RTYPE_ROOM_HPP

#include <iostream>
#include <vector>
#include <boost/asio/ip/udp.hpp>
#include "Protocol.h"
#include "Player.hpp"

class Room {
public:
    Room(int, boost::asio::ip::udp::socket &socket, int _port, boost::asio::io_service& io_service);
    ~Room(){};
    void startGame();
    bool launched = false;
    bool ready = false;
    void checkReady(t_proto &proto);
    void newPlayer(boost::asio::ip::udp::endpoint endpoint);
    int id;
    int port;
    std::vector<std::shared_ptr<Player>> players;
private:
    int freeId(int);
    void handle_send(int i);
    t_proto proto;
    boost::asio::ip::udp::socket &_socket;
    boost::asio::io_service& io_service;
};


#endif //CPP_RTYPE_ROOM_HPP
