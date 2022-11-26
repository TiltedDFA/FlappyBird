#pragma once
#include <vector>
#include "Pipe.hpp"
#include "Bird.hpp"
class Pipe_Manager
{
public:
	Pipe_Manager()=default;
	void update_pipes_pos(const sf::Time& dt);
	void gen_pipe();
	void draw_pipes();
	bool check_collision_with_player(const Bird& plyr);
private:
	std::vector<Pipe> m_pipes;
};

