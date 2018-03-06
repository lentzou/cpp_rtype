//
// Created by ant paute on 25/01/2018.
//

#include "Room.hpp"

Room::Room(int id, boost::asio::ip::udp::socket &socket, int _port, boost::asio::io_service& _io_service) : _socket(socket), port(_port), io_service(_io_service) {
    this->id = id;
    std::cout << "New Room" << std::endl;
}

int Room::freeId(int i)
{
    int min = 0;
    for (auto it : players)
    {
        if (it->id != min)
            return (min);
        min++;
    }
    return min;
}

void Room::handle_send(int i)
{
    _socket.send_to(boost::asio::buffer(&proto, sizeof(proto)), players[i]->endpoint);
}

void Room::newPlayer(boost::asio::ip::udp::endpoint endpoint)
{
    std::cout << "Player created" << std::endl;
	int id = proto.id;
	std::shared_ptr<Player>  tmp = std::make_shared<Player>(freeId(id));
    tmp->idRoom = id;
    tmp->endpoint = endpoint;
    players.push_back(tmp);
	for (auto it : players) // Envoie les anciens clients au nouveaux
	{
		if (it->id != tmp->id)
		{
			proto.ready = it->ready;
			proto.state = 102;
			proto.id = it->id;
			proto.x = it->x;
			proto.y = it->y;
			handle_send(tmp->id);
		}
	}
	proto.state = 101; // Envoie le nvx client au nouveau client
	proto.id = tmp->id;
	proto.x = tmp->x;
	proto.y = tmp->y;
	proto.ready = tmp->ready;
	handle_send(tmp->id);
	for (auto it : players) // Envoie aux anciens clients le nouveau client
    {
        proto.state = 103;
        if (it->id != tmp->id)
            handle_send(it->id);
    }
}

void Room::checkReady(t_proto &_proto)
{
	proto = _proto;
	if (proto.state == 201)
	{
		// Ready
		players[proto.id]->ready = true;
		for (auto player : players)
		{
			proto.state = 201;
			if (player->id != proto.id)
				handle_send(player->id);
		}
		int tmp = 0;
		for (auto it : players)
		{
			if (it->ready == true)
				tmp++;
		}
		if (tmp == players.size())
		{
			ready = true;
			proto.state = 203;
			handle_send(proto.id);
		}
	}
}

void Room::startGame() {
    proto.state = 202;
    proto.port = port;
    for (auto player : players)
    {
        proto.id = player->id;
        handle_send(player->id);
    }
}
