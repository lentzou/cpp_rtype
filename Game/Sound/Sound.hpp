#pragma once

#ifndef _SOUND_HPP_
# define _SOUND_HPP_

#include <iostream>
#include "Tools.hpp"
#include "IModule.hpp"

class Sound : public IModule
{
public:
	Sound(Tools &);
	virtual ~Sound() {}
	virtual void	Exec();
private:
	Tools &tools;
};

#endif
