#ifndef _SYSTEM_HPP_
# define _SYSTEM_HPP_

#include <vector>
#include "IModule.hpp"
#include "ISystem.hpp"

class System : public ISystem
{
private:
	std::vector<std::string> file;
	std::vector<IModule *> _module;
	int example;
public:
	System();
	virtual ~System();
	virtual void Execute();
	virtual void init();
	virtual void opendirectory(const std::string &);
	template<typename T, typename ... Ts>
	void loadLib(const std::string &, Ts& ... );
};
#endif /* */
