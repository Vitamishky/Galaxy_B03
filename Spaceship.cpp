#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"

spaceShip::spaceShip(sf::RenderWindow& game_window) {
    auto surface = game_window.getSize();
    spaceShip_x = spaceShip_y = 0.5f;
    spaceShipSpeed_x = 5.f / surface.x;
    spaceShipSpeed_y = 5.f / surface.y;
    spaceShipWidth = 128.f;
    spaceShipHeight = 128.f;

    if (!textureShip.loadFromFile("spaceShip.png")) {
        exit(EXIT_FAILURE);
    }


}

void spaceShip::drawSprite(sf::RenderWindow& game_window) {
    spaceShipSprite = sf::Sprite(textureShip);
    spaceShipSprite.setOrigin(spaceShipWidth, spaceShipHeight);
    auto size = game_window.getSize();
    spaceShipSprite.setPosition(spaceShip_x * size.x, spaceShip_y * size.y);
    game_window.draw(spaceShipSprite);
}

void spaceShip::moveShip(float dt, char move) {
    switch (move)
    {
        case 'l': spaceShip_x -= dt * spaceShipSpeed_x; break;
        case 'r': spaceShip_x += dt * spaceShipSpeed_x; break;
        case 'u': spaceShip_y -= dt * spaceShipSpeed_y; break;
        case 'd': spaceShip_y += dt * spaceShipSpeed_y; break;
    }
}
pair<float, float> spaceShip::getCoordinates() {
    float x = spaceShip_x;
    float y = spaceShip_y;
    pair<float, float> result = make_pair(x, y);
    return result;
}

spaceShip::~spaceShip() {}
