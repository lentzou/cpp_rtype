//
// Created by ant paute on 23/01/2018.
//

#ifndef CPP_RTYPE_PLAYER_HPP
#define CPP_RTYPE_PLAYER_HPP

#include <boost/asio/ip/udp.hpp>

class Player {
public:
    Player(int id);
    ~Player() {}
	int idRoom;
    int id;
    int x;
    int	y;
	bool ready = false;
	bool fire = false;
	boost::asio::ip::udp::endpoint endpoint;
};


#endif //CPP_RTYPE_PLAYER_HPP
