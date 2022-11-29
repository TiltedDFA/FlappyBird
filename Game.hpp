#pragma once

#include "Global.hpp"
#include<SFML/Graphics.hpp>
#include "Bird.hpp"
#include "Pipe.hpp"
#include "Pipe_Manager.hpp"
class Game
{
	//work on pipe manager class next
public:
	Game();
	void Run();
private:
	bool player_has_died();
	void game_over();
private:
	Resource_Manager m_instance;
	sf::RenderWindow m_window;
	sf::Clock m_clock;
	Bird m_bird;
	sf::Sprite m_background;
	Pipe_Manager m_pipe_manager;
};

