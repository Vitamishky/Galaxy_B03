#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"

spaceShip::spaceShip(sf::RenderWindow& game_window) {
    auto surface = game_window.getSize();
    ss_x = ss_y = 0.5f;
    ss_speed_x = 5.f / surface.x;
    ss_speed_y = 5.f / surface.y;
    ss_width = 128;
    ss_height = 128;

    if (!ship.loadFromFile("spaceShip.png")) {
        exit(EXIT_FAILURE);
    }


}

void spaceShip::drawSprite(sf::RenderWindow& game_window) {
    ss_sprite = sf::Sprite(ship);
    ss_sprite.setOrigin(ss_width / 4, ss_height / 4);
    auto size = game_window.getSize();
    ss_sprite.setPosition(ss_x * size.x, ss_y * size.y);
    game_window.draw(ss_sprite);
}

void spaceShip::moveShip(float dt, char move) {
    switch (move)
    {
        case 'l': ss_x -= dt * ss_speed_x; break;
        case 'r': ss_x += dt * ss_speed_x; break;
        case 'u': ss_y -= dt * ss_speed_y; break;
        case 'd': ss_y += dt * ss_speed_y; break;
    }
}

spaceShip::~spaceShip() {}
