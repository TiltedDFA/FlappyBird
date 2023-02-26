#pragma once
#include <vector>
#include "Pipe.hpp"
#include "Bird.hpp"
inline bool operator>=(const sf::Vector2i& one, const sf::Vector2i& two)
{
	if (one.x >= two.x) return true;
	return false;
}
class Pipe_Manager
{
public:
	Pipe_Manager();
	
	//used to generate a pipe
	void gen_pipe();
	void draw_pipes(sf::RenderWindow& window)const;
	[[nodiscard]] bool check_collision_with_player(const Bird& plyr)const;
	void update(const sf::Time& dt);
	bool has_player_passed_pipe(const sf::Vector2i& player_pos);
private:
	std::vector<Pipe> m_pipes;
	sf::Clock m_pipe_timer;
	int m_current_pipe_index;
};

