#include "Game.hpp"
Game::Game()
{
	m_window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird");
    m_bird.set_position(sf::Vector2f(100, 300));
    m_background.setTexture(Resource_Manager::get_texture(BACKGROUND_TXTR_PATH));
    m_test.set_position(sf::Vector2f(200, 650));
    m_test.set_orientation(false);
    m_test.init_pipe();
}
bool Game::player_has_died() {
    if (m_bird.get_position().y + BIRD_SPRITE_HEIGHT > SCREEN_HEIGHT) {
        return true;
        //include pipe collision checking here
    }
    else {
        return false;
    }
}
void Game::game_over() {
    while (m_window.isOpen())
    {
        sf::Time delta_time = m_clock.restart();
        sf::Event event;
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
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_bird.get_global_bounds().top > 50) {
            m_bird.flap();
        }
        if (player_has_died()) {
            break;
        }
        m_bird.update(delta_time);
        
        m_window.clear();
        m_window.draw(m_background);
        m_test.draw(m_window);
        m_bird.draw(m_window);
        m_window.display();
    }   
    game_over();
}