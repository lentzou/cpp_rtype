#include "Server.hpp"

int main(int argc, char **argv)
{
	try
	{
		boost::asio::io_service io_service;
		std::unique_ptr<Server> server =  std::make_unique<Server>(SERVER_PORT, io_service);
		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
