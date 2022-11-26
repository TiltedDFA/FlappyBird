#pragma once
#include "Global.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Resource_Manager.hpp"
class Pipe
{
public:
	Pipe()=default;
	void set_orientation(const bool& is_upright);
	void set_position(const sf::Vector2f& position);
	void init_pipe();
	void draw(sf::RenderWindow& window);
private:
	bool m_is_upright;
	sf::Sprite m_head;
	std::vector<sf::Sprite> m_tail;
};

