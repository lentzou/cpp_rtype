#pragma once

#ifndef _INPUT_HPP_
# define _INPUT_HPP_

#include <iostream>
#include "Tools.hpp"
#include "IModule.hpp"

class Input : public IModule
{
public:
	Input(Tools &);
	virtual ~Input() {}
	virtual void Exec();
private:
	Tools &tools;
};

#endif
