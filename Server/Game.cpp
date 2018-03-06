//
// Created by ant paute on 26/01/2018.
//

#include "Game.hpp"

Game::Game(int _port, boost::asio::io_service &_io_service, std::vector<std::shared_ptr<Player>> &_players)
            : _socket(_io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), (unsigned short)_port)), players(_players), io_service(_io_service)
{
    std::cout << "New Game" << std::endl;
	std::thread t1(&Game::start_receive, this);
	t1.join();
}

Game::~Game()
{
}

void Game::start_receive()
{
    _socket.async_receive_from(
            boost::asio::buffer(&proto, sizeof(proto)), _remote_endpoint,
            [this](const boost::system::error_code &error,
                   std::size_t bytes)
            {
                create_player(_remote_endpoint);
            });
}

int Game::getId(boost::asio::ip::udp::endpoint endpoint) 
{
    for (auto it : players)
    {
        if (it->endpoint == endpoint)
            return (it->id);
    }
}

void Game::create_player(boost::asio::ip::udp::endpoint endpoint)
{
    switch (proto.state)
    {
        case 301:
            int id;
            id = proto.id;
            players[proto.id]->endpoint = endpoint;
            handle_send(id);
            break ;
        case 302:
            if (players[proto.id]->x < 1425)
                players[proto.id]->x += 10;
            proto.x = players[proto.id]->x;
            handle_all();
            break ;
        case 303:
            if (players[proto.id]->x > 0)
                players[proto.id]->x -= 10;
            proto.x = players[proto.id]->x;
            handle_all();
            break ;
        case 304:
            if (players[proto.id]->y < 860)
                players[proto.id]->y += 10;
            proto.y = players[proto.id]->y;
            handle_all();
            break ;
        case 305:
            if (players[proto.id]->y > 0)
                players[proto.id]->y -= 10;
            proto.y = players[proto.id]->y;
            handle_all();
            break ;
        case 306:
            handle_all();
            break ;
        case 307:
            proto.x = 1200 + std::rand() % 200;
            proto.y = 20 + std::rand() % 800;
            handle_all();
            break ;
		case 308:
			handle_all();
			break;
		case 309:
			players.erase(players.begin() + proto.id);
			handle_all();
			break;
	}
	start_receive();
}

void Game::handle_send(int i)
{
	_socket.send_to(boost::asio::buffer(&proto, sizeof(proto)), players[i]->endpoint);
}

void Game::handle_all()
{
	for (auto player : players)
	_socket.send_to(boost::asio::buffer(&proto, sizeof(proto)), player->endpoint);
}
