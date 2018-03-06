#include "StarField.hpp"

//starfield won't work without proper data
Starfield::Starfield() : maxStars(0), x_Size(800), y_Size(800)
{
}

void Starfield::init(int xResolution, int yResolution)
{
	x_Size = xResolution - 10;
	y_Size = yResolution - 10;


	//create the images that will be used to update the background texture
	smallStarImage.create(1, 1, sf::Color::White);
	mediumStarImage.create(2, 2, sf::Color::White);
	largeStarImage.create(4, 4, sf::Color::White);

	//init random generator
	my_distribution_x = std::uniform_int_distribution<int>(10, xResolution - 10);
	my_distribution_y = std::uniform_int_distribution<int>(10, yResolution - 10);
	my_distribution_size = std::uniform_int_distribution<int>(1, 4);
	seed.seed((unsigned int)time(NULL));
	maxStars = 500;

	//generate a start set of stars
	while ((int)star.size() <= maxStars)
	{
		tmp.size = my_distribution_size(seed);
		tmp.XPos = my_distribution_x(seed);
		tmp.YPos = my_distribution_y(seed);
		star.push_back(tmp);
	}
}

void Starfield::updateStarfield()
{
	//remove all stars that have exceeded the lower screen border
	star.erase(std::remove_if(star.begin(), star.end(), [&](Star& p_Star) {
		return (p_Star.XPos < p_Star.size);
	}
	), star.end());

	//move every star, according to its size to create a parallax effect
	std::for_each(star.begin(), star.end(), [&](Star& p_Star) {
		p_Star.XPos -= p_Star.size;
	}
	);

	//create new stars until the set limit is reached
	while ((int)star.size() <= maxStars)
	{
		tmp.size = my_distribution_size(seed);
		tmp.XPos = x_Size - 1;
		tmp.YPos = my_distribution_y(seed);
		star.push_back(tmp);
	}

}

//update a target texture with all stars contained in this starfield
void Starfield::drawStarfield(sf::Texture& p_Texture)
{
	for (vector<Star>::iterator it = star.begin(); it != star.end(); ++it)
	{
		if (it->size == 1)
			p_Texture.update(smallStarImage, it->XPos, it->YPos);
		else if (it->size == 2)
			p_Texture.update(mediumStarImage, it->XPos, it->YPos);
		else if (it->size == 3)
			p_Texture.update(largeStarImage, it->XPos, it->YPos);
	}
}
