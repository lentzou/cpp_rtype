#ifndef _IMODULE_HPP_
#define _IMODULE_HPP_

#include "Tools.hpp"

class IModule
{
public:
	virtual ~IModule() {}
	virtual void Exec() = 0;
};

#endif //IModule
