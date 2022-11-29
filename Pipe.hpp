#pragma once
#include "Global.hpp"
#include <vector>
#include "Bird.hpp"
#include <SFML/Graphics.hpp>
#include "Resource_Manager.hpp"
class Pipe
{
public:
	Pipe()=default;
	sf::Vector2i get_position()const;
	bool check_collision_with_plyr(const Bird& plyr)const;
	void set_orientation(const bool& is_upright);
	void set_position(const sf::Vector2f& position);
	void init_pipe();
	void move(const float& x_offset, const float& y_offset);
	void draw(sf::RenderWindow& window)const;
private:
	bool m_is_upright;
	sf::Sprite m_head;
	std::vector<sf::Sprite> m_tail;
};

