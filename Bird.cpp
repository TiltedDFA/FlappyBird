#include "Bird.hpp"
Bird::Bird() {
	m_sprite.setPosition(sf::Vector2f(0,0));
	m_sprite.setTexture(Resource_Manager::get_texture(BIRD_IMG_PATH));
	m_sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
	m_vertical_speed = 0;
}
sf::FloatRect Bird::get_global_bounds()const {
	return m_sprite.getGlobalBounds();
}
void Bird::set_position(const sf::Vector2f& pos) {
	m_sprite.setPosition(pos);
}
sf::Vector2f Bird::get_position() {
	return m_sprite.getPosition();
}
void Bird::draw(sf::RenderWindow& window) {
	window.draw(m_sprite);
}
void Bird::update(const sf::Time& dt) {
	sf::Vector2f old_pos = m_sprite.getPosition();
	if (old_pos.y + BIRD_SPRITE_HEIGHT > SCREEN_HEIGHT) {
		m_sprite.setTextureRect(sf::IntRect(80, 0, 40, 40));
		return;
	}
		
	if (m_vertical_speed > 0) {
		m_sprite.setTextureRect(sf::IntRect(40,0,40,40));
	}
	else {
		m_sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
	}

	m_vertical_speed += GRAVITY * dt.asSeconds();
	m_sprite.setPosition(sf::Vector2f(old_pos.x + BIRD_X_SPEED*dt.asSeconds(), old_pos.y + m_vertical_speed *dt.asSeconds()));
}
void Bird::flap() {
	m_sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
	m_vertical_speed = -200;
}