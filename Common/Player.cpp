//
// Created by ant paute on 23/01/2018.
//

#include "Player.hpp"

Player::Player(int i)
{
	id = i;
	switch (id) {
	case 0:
		x = 0;
		y = 100;
		break;
	case 1:
		x = 0;
		y = 325;
		break;
	case 2:
		x = 0;
		y = 550;
		break;
	case 3:
		x = 0;
		y = 775;
		break;
	}
	ready = false;
}