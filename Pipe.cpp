#include "Pipe.hpp"
void Pipe::set_orientation(const bool& is_upright) {
	m_is_upright = is_upright;
	m_head.setRotation(180);
}
void Pipe::set_position(const sf::Vector2f& position) {
	m_head.setPosition(position);
}
void Pipe::init_pipe() {
	if (m_is_upright) {
		
	}
	else {
		m_head.setTexture(Resource_Manager::get_texture(PIPE_HEAD_PATH));
		//m_head.setRotation(180);
		m_head.setPosition(sf::Vector2f(m_head.getPosition().x + PIPE_HEAD_WIDTH, m_head.getPosition().y));
		int num_pipe_tails = (static_cast<int>(m_head.getPosition().y) - PIPE_HEAD_HEIGHT) / PIPE_TAIL_HEIGHT;
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
void Pipe::draw(sf::RenderWindow& window) {
	window.draw(m_head);
	for (int i = 0; i < m_tail.size(); ++i) {
		window.draw(m_tail[i]);
	}
}