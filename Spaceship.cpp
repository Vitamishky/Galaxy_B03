#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Spaceship.h"

Spaceship::Spaceship(sf::RenderWindow& game_window) {
    auto surface = game_window.getSize();
    ss_x = surface.x / 2;
    ss_y = surface.y / 2;
    ss_speed = 5;
    ss_width = 128;
    ss_height = 128;
    ss_radius = ss_width / 2;

}
void Spaceship::drawsprite(sf::RenderWindow& game_window) {
    sf::Texture ship;
    if (!ship.loadFromFile("space-shuttle.png")) {
        //return EXIT_FAILURE;
    }
    sf::Sprite ss_sprite(ship);
    ss_sprite.setPosition(ss_x - ss_sprite.getGlobalBounds().width / 2, ss_y - ss_sprite.getGlobalBounds().height / 2);
    game_window.draw(ss_sprite);
}

void Spaceship::moveship(char move) {
    if (move == 'l') { ss_x -= ss_speed; }
    else if (move == 'r') { ss_x += ss_speed; }
    else if (move == 'u') { ss_y -= ss_speed; }
    else if (move == 'd') { ss_y += ss_speed; }
}

Spaceship::~Spaceship() {}
