#pragma once
#include <SFML/Graphics.hpp>
#include "Resource_Manager.hpp"
#include "Global.hpp"
class Bird
{
public:
	Bird();

	sf::FloatRect get_global_bounds()const;
	void set_position(const sf::Vector2f& pos);
	sf::Vector2f get_position();
	void draw(sf::RenderWindow& window);
	void update(const sf::Time& dt);	
	void flap();
private:
	sf::Sprite m_sprite;
	float m_vertical_speed;
};

