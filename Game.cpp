#include "Game.hpp"
Game::Game()
{
    srand(time(NULL));
	m_window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird");
    m_window.setFramerateLimit(60);
    sf::Image icon_temp;
    icon_temp.loadFromFile(PIPE_HEAD_PATH);
    m_window.setIcon(icon_temp.getSize().x, icon_temp.getSize().y,icon_temp.getPixelsPtr());
    m_bird.set_position(sf::Vector2f(50, 300));
    m_background.setTexture(Resource_Manager::get_texture(BACKGROUND_TXTR_PATH));
    m_space_pressed = false;
    m_plyr_score = 0;
    m_score_txt.setCharacterSize(50);
    m_score_txt.setOutlineColor(sf::Color::Black);
    m_score_txt.setOutlineThickness(3);
    m_score_txt.setFont(Resource_Manager::get_font(SCORE_TXT));
	m_score_txt.setPosition((SCREEN_WIDTH / 2) -20, SCREEN_HEIGHT / 8);
    m_score_txt.setString(std::to_string(m_plyr_score));
}
bool Game::player_has_died() {
    if (m_bird.get_position().y + BIRD_SPRITE_HEIGHT > SCREEN_HEIGHT) {
        return true;
    }
    if (m_pipe_manager.check_collision_with_player(m_bird)) {
        return true;
    }
    return false;
}
void Game::game_over() {
    while (m_window.isOpen())
    {
        sf::Time delta_time = m_clock.restart();
        sf::Event event{};
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }
        m_bird.update(delta_time);

        m_window.clear();
        m_window.draw(m_background);
        m_bird.draw(m_window);
        m_window.display();
    }
}
void Game::Run() {
    m_clock.restart();
    while (m_window.isOpen())
    {
        sf::Time delta_time = m_clock.restart();
        sf::Event event{};
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
                m_space_pressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_bird.get_global_bounds().top > 50
            && !m_space_pressed) {
            m_bird.flap();
            m_space_pressed = true;
        }
        if (player_has_died()) {
            break;
        }
        if (m_pipe_manager.has_player_passed_pipe(sf::Vector2i(m_bird.get_position())))
        {
            ++m_plyr_score;
            m_score_txt.setString(std::to_string(m_plyr_score));
        }
        m_bird.update(delta_time);
        m_pipe_manager.update(delta_time);
        

        m_window.clear();
        m_window.draw(m_background);
        m_pipe_manager.draw_pipes(m_window);
        m_bird.draw(m_window);
        m_window.draw(m_score_txt);
        m_window.display();
    }   
    game_over();
}