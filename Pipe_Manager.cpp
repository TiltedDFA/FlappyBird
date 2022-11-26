#include "Pipe_Manager.hpp"
void Pipe_Manager::update_pipes_pos(const sf::Time& dt) {
	for (int i = 0; i < m_pipes.size(); ++i) {
		m_pipes[i].move(BIRD_X_SPEED * dt.asSeconds(),0);
	}
}
void Pipe_Manager::gen_pipe() {

}
void Pipe_Manager::draw_pipes() {

}
bool Pipe_Manager::check_collision_with_player(const Bird& plyr){
	return false;
}