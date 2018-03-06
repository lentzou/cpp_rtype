#include "tmp.hpp"

tmp::tmp()
{
}

void tmp::go(std::string port, std::string ip)
{
	boost::asio::io_service io_service;
	std::shared_ptr<Network> net;
	net = std::make_shared<Network>(io_service, ip, port);
}
