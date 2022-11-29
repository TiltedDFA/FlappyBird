#include "Pipe_Manager.hpp"
#include<random>
Pipe_Manager::Pipe_Manager() {
	m_pipe_timer.restart();
}
void Pipe_Manager::update(const sf::Time& dt) {
	if (m_pipes.size() == 0) {
		gen_pipe();
	}
	for (int i = 0; i < m_pipes.size(); ++i) {
		m_pipes[i].move(BIRD_X_SPEED * dt.asSeconds(),0);
	}
	if (m_pipes[0].get_position().x <= 0 - PIPE_HEAD_WIDTH) {
		m_pipes.erase(m_pipes.begin());
	}
	if (m_pipe_timer.getElapsedTime().asSeconds() >= TIME_BETWEEN_PIPE_GEN) {
		gen_pipe();
		m_pipe_timer.restart();
	}
}
void Pipe_Manager::gen_pipe() {
	Pipe temp_top, temp_bottom;

	//this is the height for the top pipe;
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rand_pipe_height(PIPE_MIN_Y, PIPE_MAX_Y);
	int random_y_height = rand_pipe_height(rng);

	temp_top.set_orientation(false);
	temp_top.set_position(sf::Vector2f(400, random_y_height));
	temp_bottom.set_orientation(true);
	temp_bottom.set_position(sf::Vector2f(400, (random_y_height + PIPE_Y_SPACING)));
	temp_top.init_pipe();
	temp_bottom.init_pipe();
	m_pipes.push_back(temp_top);
	m_pipes.push_back(temp_bottom);
}
void Pipe_Manager::draw_pipes(sf::RenderWindow& window) {
	for (const Pipe& i : m_pipes) {
		i.draw(window);
	}
}
bool Pipe_Manager::check_collision_with_player(const Bird& plyr){
	for (int i = 0; i < m_pipes.size(); ++i) {
		if (m_pipes[i].check_collision_with_plyr(plyr)) {
			return true;
		}
	}
	return false;
}