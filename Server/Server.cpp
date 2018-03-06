#include "Server.hpp"

Server::Server(int _port, boost::asio::io_service &_io_service) 
	: _socket(_io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), _port)) , io_service(_io_service)
{
    std::cout << "Server started" << std::endl;
    port = _port;
    rooms.push_back(std::make_shared<Room>(0, _socket, ++port, io_service));
    start_receive();
}

Server::~Server()
{
}

void Server::start_receive()
{
	try
	{
		_socket.async_receive_from(
			boost::asio::buffer(&proto, sizeof(proto)), _remote_endpoint,
			[this](const boost::system::error_code &error,
				std::size_t bytes)
		{
			create_player(_remote_endpoint);
		});
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int Server::freeRoom()
{
    int free = -1;
    for (auto it : rooms) {
        free++;
        if (it->players.size() < 4) {
            return (it->id);
        }
    }
    if ((unsigned int)free < rooms.size()) {
	    rooms.push_back(std::make_shared<Room>(free + 1, _socket, ++port, io_service));
        return (rooms.size() - 1);
    }
}

int Server::getRoom(boost::asio::ip::udp::endpoint endpoint) {
    for (auto room : rooms) {
        for (auto player : room->players) {
            if (player->endpoint == endpoint)
                return (room->id);
        }
    }
}

void Server::create_player(boost::asio::ip::udp::endpoint endpoint) {
	launchGame();
	if (proto.state == 101) // Nouveau client
	{
		rooms[freeRoom()]->newPlayer(endpoint);
	}
	else {
        rooms[getRoom(endpoint)]->checkReady(proto);
    }
    start_receive();
}

void Server::launchGame() {
    for (auto room : rooms) {
	    if (room->ready == true && room->launched == false) {
			room->launched = true;
			Game *game = new Game(room->port, io_service, room->players);       
			room->startGame();
		}
    }
}
