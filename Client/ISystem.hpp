#ifndef _ISYSTEM_H_
# define _ISYSTEM_H_

#include "Tools.hpp"
#include <iostream>

/* path for dll*/


/* interface system , load lib and loop*/

class ISystem
{
public:
	virtual ~ISystem() {}
	virtual void Execute() = 0;
	virtual void opendirectory(const std::string &) = 0;
};

#endif 
