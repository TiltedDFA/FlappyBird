#include "Pipe.hpp"
sf::Vector2i Pipe::get_position()const {
	return sf::Vector2i(m_head.getPosition());
}
void Pipe::set_orientation(const bool& is_upright) {
	m_is_upright = is_upright;
	if(!is_upright) 
		m_head.setRotation(180);
}
bool Pipe::check_collision_with_plyr(const Bird& plyr)const {
	if (m_head.getGlobalBounds().intersects(plyr.get_global_bounds())) {
		return true;
	}
	for (const auto& i : m_tail) {
		if(i.getGlobalBounds().intersects(plyr.get_global_bounds())) {
			return true;
		}
	}
	return false;
}
void Pipe::set_position(const sf::Vector2f& position) {
	m_head.setPosition(position);
}
void Pipe::init_pipe() {
	if (m_is_upright) {
		m_head.setTexture(Resource_Manager::get_texture(PIPE_HEAD_PATH));
		const int num_pipe_tails = ((SCREEN_HEIGHT - (static_cast<int>(m_head.getPosition().y) + PIPE_HEAD_HEIGHT))
			/ PIPE_TAIL_HEIGHT)+1;
		for (int i = 0; i < num_pipe_tails; ++i) {
			sf::Sprite tail_segment;
			tail_segment.setTexture(Resource_Manager::get_texture(PIPE_TAIL_PATH));
			tail_segment.setPosition(
				m_head.getPosition().x + ((PIPE_HEAD_WIDTH - PIPE_TAIL_WIDTH) / 2),
				m_head.getPosition().y + PIPE_HEAD_HEIGHT + ((i) * PIPE_TAIL_HEIGHT)
			);
			m_tail.push_back(tail_segment);
		}
	}
	else {
		m_head.setTexture(Resource_Manager::get_texture(PIPE_HEAD_PATH));
		//this is to adjust for the rotation
		m_head.setPosition(sf::Vector2f(m_head.getPosition().x + PIPE_HEAD_WIDTH, m_head.getPosition().y));
		const int num_pipe_tails = ((static_cast<int>(m_head.getPosition().y) - PIPE_HEAD_HEIGHT) / PIPE_TAIL_HEIGHT)+1;
		for (int i = 0; i < num_pipe_tails; ++i) {
			sf::Sprite tail_segment;
			tail_segment.setTexture(Resource_Manager::get_texture(PIPE_TAIL_PATH));
			tail_segment.setPosition(
				m_head.getPosition().x - (((PIPE_HEAD_WIDTH - PIPE_TAIL_WIDTH) / 2) + PIPE_TAIL_WIDTH),
				m_head.getPosition().y - PIPE_HEAD_HEIGHT - ((i + 1) * PIPE_TAIL_HEIGHT)
			);
			m_tail.push_back(tail_segment);
		}
	}
}
void Pipe::move(const float& x_offset, const float& y_offset) {
	m_head.move(sf::Vector2f(std::floor(-x_offset), std::floor(y_offset)));
	for (int i = 0; i < m_tail.size(); ++i) {
		m_tail[i].move(std::floor( - x_offset), std::floor(y_offset));
	}
}
void Pipe::draw(sf::RenderWindow& window)const {
	window.draw(m_head);
	for (int i = 0; i < m_tail.size(); ++i) {
		window.draw(m_tail[i]);
	}
}