#pragma once

#ifndef _SFML_HPP_
# define _SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "IGraph.hpp"
#include "StarField.hpp"

class Sfml : public IGraph
{
public:
	Sfml();
	virtual					~Sfml() {}
	virtual void			PrintSprite(int x, int y, int index);
	virtual void			PrintExplosion(int x, int y);
	virtual void			PrintText(std::string str, int x, int y, int size, bool focus);
	virtual void			Display();
	virtual void			Clear();
	virtual void			StarField();
	virtual void			SetInput(Keys &, std::string &ip, std::string &port, bool focus, bool game);
	virtual void			PlaySound(Sounds &);
	virtual bool			IsOpen();
	virtual void			Close();
private:
	std::shared_ptr<sf::RenderWindow>	window;
	Starfield				backgroundStars;
	sf::Image				starsImage;
	sf::Texture				starsTexture;
	sf::Sprite				starsSprite;
	sf::Vector2u			screenDimensions;
	sf::Font				font;
	sf::Text				text;
	sf::Music				musics[15];
	std::vector<sf::Sprite>	sprites;
	sf::Texture				ship;
	sf::Texture				shoot;
	sf::Texture				enemy;
	sf::Texture				explosion;
};

#endif
