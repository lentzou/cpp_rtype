#pragma once

#ifndef STARFIELD_H
#define STARFIELD_H

#include <SFML/Graphics.hpp>
#include <random>
#include <vector>
#include <ctime>


using std::vector;

class Starfield
{
	

public:
	Starfield();
	~Starfield() {}

	void updateStarfield();
	void drawStarfield(sf::Texture&);
	void init(int xResolution, int yResolution);

private:
	struct Star{
		int size;
		int XPos;
		int YPos;
	};
	int maxStars;

	int x_Size;
	int y_Size;

	vector<Star> star;
	Star tmp;

	std::default_random_engine seed;
	std::uniform_int_distribution<int> my_distribution_x;
	std::uniform_int_distribution<int> my_distribution_y;
	std::uniform_int_distribution<int> my_distribution_size;
	
	sf::Image smallStarImage;
	sf::Image mediumStarImage;
	sf::Image largeStarImage;
};

#endif // STARFIELD_H
