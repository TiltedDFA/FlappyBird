#pragma once

#include "Global.hpp"
#include<SFML/Graphics.hpp>
#include "Bird.hpp"
#include "Pipe.hpp"
class Game
{
public:
	Game();
	void Run();
private:
	bool player_has_died();
	void game_over();
private:
	Resource_Manager m_instance;
	Pipe m_test, m_test2;
	sf::RenderWindow m_window;
	sf::Clock m_clock;
	Bird m_bird;
	sf::Sprite m_background;
};

