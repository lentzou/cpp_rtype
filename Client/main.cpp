#include <iostream>
#include <thread>
#include <memory>
#include "Data.hpp"
#include "Network.hpp"
#include "System.hpp"
#include "Client.hpp"
#include "tmp.hpp"
//#include "Sfml.hpp"

void run()
{
	System game;
	game.init();
	game.Execute();
}

void go()
{
	Tools &tools = Tools::Instance();

	while (true) {
		if (tools.getConnect() == true)
			break;
	}
	std::cout << tools.getIp() << std::endl;
	std::cout << tools.getPort() << std::endl;
	boost::asio::io_service io_service;
	std::shared_ptr<Network> net = std::make_shared<Network>(io_service, tools.getIp() , tools.getPort());
	std::thread t2([net]() {net->checkTools(); });
	std::thread t1([net]() {net->receiverServer(); });
	t2.join();
	t1.join();
	boost::asio::io_service __io_service;
	std::shared_ptr<Client> client = std::make_shared<Client>(__io_service, net->ip, net->port, net->id);
	std::thread t3([client]() {client->checkTools(); });
	std::thread t4([client]() {client->receiverServer(); });
	t3.join();
	t4.join();
}

int main(int ac, char **av)
{
	try
	{
		std::thread t1(run);
		std::thread t2(go);
		t1.join();
		t2.join();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
