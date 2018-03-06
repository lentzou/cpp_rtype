#include "Sfml.hpp"

#ifdef __linux__

extern "C"
{
        IGraph *create_lib()
        {
                return new Sfml();
        }
}

#elif _WIN32

typedef IGraph * lib;

extern "C"
{
    lib __declspec(dllexport) create_lib() {
        return new Sfml();
    }
}

#endif

Sfml::Sfml()
{
	sf::Sprite			sprite;
	sf::Music			music;
	screenDimensions.x = HEIGHT;
	screenDimensions.y = WIDTH;
	this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(screenDimensions.x, screenDimensions.y, 32), "Game", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(60);
	starsImage.create(HEIGHT, WIDTH, sf::Color::Black);
	starsTexture.loadFromImage(starsImage);
	starsTexture.setSmooth(false);
	starsSprite.setTexture(starsTexture);
	starsSprite.setPosition(0, 0);
	backgroundStars.init(HEIGHT, WIDTH);
	
	font.loadFromFile("../Lib/Assets/Game.ttf");

	musics[0].openFromFile("../Lib/Assets/Start.wav");
	musics[1].openFromFile("../Lib/Assets/Menu.wav");
	musics[2].openFromFile("../Lib/Assets/Credit.wav");
	musics[3].openFromFile("../Lib/Assets/Lobby.wav");
	musics[4].openFromFile("../Lib/Assets/Game.wav");
	musics[5].openFromFile("../Lib/Assets/Allo.wav");
	musics[6].openFromFile("../Lib/Assets/Effect.wav");
	musics[7].openFromFile("../Lib/Assets/Fire.wav");
	musics[8].openFromFile("../Lib/Assets/Porte.wav");
	musics[9].openFromFile("../Lib/Assets/Ahjaou.wav");
	musics[10].openFromFile("../Lib/Assets/Non.wav");
	musics[11].openFromFile("../Lib/Assets/Nope.wav");
	musics[12].openFromFile("../Lib/Assets/OLED.wav");
	musics[13].openFromFile("../Lib/Assets/Oui.wav");
	musics[14].openFromFile("../Lib/Assets/Vody.wav");

	ship.loadFromFile("../Lib/Assets/r-typesheet42.gif");
	shoot.loadFromFile("../Lib/Assets/r-typesheet1.gif");
	enemy.loadFromFile("../Lib/Assets/enemy.png");
	explosion.loadFromFile("../Lib/Assets/r-typesheet16.gif");
	sprite.setTexture(ship);
	sprite.setScale(sf::Vector2f(2, 2));
	sprite.setTextureRect(sf::IntRect(0, 0, 34, 18));
	sprites.push_back(sprite);
	sprite.setTextureRect(sf::IntRect(0, 18, 34, 18));
	sprites.push_back(sprite);
	sprite.setTextureRect(sf::IntRect(0, 36, 34, 18));
	sprites.push_back(sprite);
	sprite.setTextureRect(sf::IntRect(0, 53, 34, 18));
	sprites.push_back(sprite);

	sprite.setTexture(shoot);
	sprite.setTextureRect(sf::IntRect(230, 100, 17, 15));
	sprites.push_back(sprite);

	sprite.setTexture(enemy);
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	sprite.setTextureRect(sf::IntRect(20, 0, 150, 200));
	sprites.push_back(sprite);
}

void Sfml::PrintExplosion(int x, int y)
{
	clock_t startTime = clock();
	srand((unsigned int)time(NULL));
	sf::Sprite			sprite;
	
	sprite.setTexture(explosion);
	sprite.setScale(sf::Vector2f(2, 2));
	sprite.setPosition(sf::Vector2f(x, y));
	
	if ((((int)startTime / CLOCKS_PER_SEC) % 2) == 0)
	{
		sprite.setTextureRect(sf::IntRect(140, 40, 30, 30));
		window->draw(sprite);
	}
	else
	{
		sprite.setTextureRect(sf::IntRect(80, 40, 30, 30));
		window->draw(sprite);
	}
}


void Sfml::PrintSprite(int x, int y, int index)
{
	sprites[index].setPosition(sf::Vector2f(x, y));
	window->draw(sprites[index]);
}

void Sfml::PrintText(std::string Text, int x, int y, int size, bool focus)
{
	text.setString(Text);
	text.setCharacterSize(size);
	text.setFont(font);
	#ifdef _WIN32
		text.setFillColor(focus == true ? sf::Color::Yellow : sf::Color::White);
	#elif __linux__
		text.setColor(focus == true ? sf::Color::Yellow : sf::Color::White);
	#endif	
	text.setPosition(sf::Vector2f((HEIGHT / 2.0f) + x, (WIDTH / 2.0f) + y));
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	window->draw(text);
}

void Sfml::Display()
{
	window->display();
}

void Sfml::Clear()
{
	window->clear();
}

void Sfml::StarField()
{
	starsTexture.loadFromImage(starsImage);
	backgroundStars.drawStarfield(starsTexture);
	window->clear(sf::Color(0, 0, 0));
	window->draw(starsSprite);
	backgroundStars.updateStarfield();
}

bool Sfml::IsOpen()
{
	return (window->isOpen());
}

void			Sfml::SetInput(Keys &keys, std::string &ip, std::string &port, bool focus, bool game)
{
	sf::Event	event;

	keys = { false, false, false, false, false, false, false, false };
	if (window == nullptr)
		return;
	if (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				keys.KQUIT = true;
			if (event.type == sf::Event::KeyPressed)
				keys.KANY = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				keys.KENTER = true;
			else if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == '\b')
				{
					if (port.size() > 0 && focus == true)
						port.erase(port.size() - 1, 1);
					if (ip.size() > 0 && focus == false)
						ip.erase(ip.size() - 1, 1);
				}
				else if ((event.text.unicode >= '0' && event.text.unicode <= '9') && focus == true)
					port += static_cast<char>(event.text.unicode);
				else if (((event.text.unicode >= '0' && event.text.unicode <= '9')
					|| event.text.unicode == '.') && focus == false)
					ip += static_cast<char>(event.text.unicode);
				if (game == false)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
						keys.KESC = true;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
						keys.KLEFT = true;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						keys.KRIGHT = true;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
						keys.KUP = true;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						keys.KDOWN = true;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
						keys.KSPACE = true;					
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
					keys.KENEMY = true;
			}
		}
		if (game == true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				keys.KESC = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				keys.KLEFT = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				keys.KRIGHT = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
				keys.KUP = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				keys.KDOWN = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				keys.KSPACE = true;
		}
	}
}

void			Sfml::PlaySound(Sounds &sounds)
{
	if (sounds.START == true)
	{
		musics[1].stop();

		musics[0].play();
		musics[0].setVolume(100);
		musics[0].setLoop(true);
		sounds.START = false;
	}
	else if (sounds.MENU == true)
	{
		musics[0].stop();
		musics[2].stop();
		musics[3].stop();

		musics[1].play();
		musics[1].setVolume(100);
		musics[1].setLoop(true);
		sounds.MENU = false;
	}
	else if (sounds.CREDIT == true)
	{
		musics[1].stop();

		musics[2].play();
		musics[2].setVolume(100);
		musics[2].setLoop(true);
		sounds.CREDIT = false;
	}
	else if (sounds.LOBBY == true)
	{
		musics[1].stop();
		musics[4].stop();

		musics[3].play();
		musics[3].setVolume(100);
		musics[3].setLoop(true);
		sounds.LOBBY = false;
	}
	else if (sounds.GAME == true)
	{
		musics[3].stop();
		musics[4].play();
		musics[4].setVolume(100);
		musics[4].setLoop(true);
		sounds.GAME = false;
	}

	if (sounds.BONUS == true)
	{
		musics[5].play();
		musics[5].setVolume(100);
		sounds.BONUS = false;
	}

	if (sounds.EFFECT == true)
	{
		musics[6].play();
		musics[6].setVolume(100);
		sounds.EFFECT = false;
	}

	if (sounds.FIRE == true)
	{
		musics[7].play();
		musics[7].setVolume(100);
		sounds.FIRE = false;
	}

	if (sounds.PORTE == true)
	{
		musics[8].play();
		musics[8].setVolume(500);
		sounds.PORTE = false;
	}

	if (sounds.AHJAOU == true)
	{
		musics[9].play();
		musics[9].setVolume(100);
		sounds.AHJAOU = false;
	}
	if (sounds.NON == true)
	{
		musics[10].play();
		musics[10].setVolume(100);
		sounds.NON = false;
	}
	if (sounds.NOPE == true)
	{
		musics[11].play();
		musics[11].setVolume(100);
		sounds.NOPE = false;
	}
	if (sounds.OLED == true)
	{
		musics[12].play();
		musics[12].setVolume(100);
		sounds.OLED = false;
	}
	if (sounds.OUI == true)
	{
		musics[13].play();
		musics[13].setVolume(100);
		sounds.OUI = false;
	}
	if (sounds.VODY == true)
	{
		musics[14].play();
		musics[14].setVolume(100);
		sounds.VODY = false;
	}

	if (!(window->isOpen()))
	{
		musics[0].stop();
		musics[1].stop();
		musics[2].stop();
		musics[3].stop();
		musics[4].stop();
		musics[5].stop();
		musics[6].stop();
		musics[7].stop();
		musics[8].stop();
		musics[9].stop();
		musics[10].stop();
		musics[11].stop();
		musics[12].stop();
		musics[13].stop();
		musics[14].stop();

	}
}

void			Sfml::Close()
{
	window->close();
}
