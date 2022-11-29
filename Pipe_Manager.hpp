#pragma once
#include <vector>
#include "Pipe.hpp"
#include "Bird.hpp"
class Pipe_Manager
{
public:
	Pipe_Manager();
	
	//used to generate a pipe
	void gen_pipe();
	void draw_pipes(sf::RenderWindow& window);
	bool check_collision_with_player(const Bird& plyr);
	void update(const sf::Time& dt);
private:
	std::vector<Pipe> m_pipes;
	sf::Clock m_pipe_timer;
};

