#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceObjects.h"

spaceObjects::spaceObjects(sf::RenderWindow& game_window) {
    auto surface = game_window.getSize();
    spaceObjects_x = spaceObjects_y = 0.5f;
    spaceObjectsSpeed_x = 5.f / surface.x;
    spaceObjectsSpeed_y = 5.f / surface.y;
    spaceObjectsWidth = 128;
    spaceObjectsHeight = 128;

    if (!textureObjects.loadFromFile("spaceObjects.png")) {
        exit(EXIT_FAILURE);
    }


}

void spaceObjects::drawSprite(sf::RenderWindow& game_window) {
    spaceObjectsSprite = sf::Sprite(textureObjects);
    spaceObjectsSprite.setOrigin(spaceObjectsWidth / 4, spaceObjectsHeight / 4);
    auto size = game_window.getSize();
    spaceObjectsSprite.setPosition(spaceObjects_x * size.x, spaceObjects_y * size.y);
    game_window.draw(spaceObjectsSprite);
}

void spaceObjects::moveObjects(float dt, char move) {
    switch (move)
    {
    case 'l': spaceObjects_x -= dt * spaceObjectsSpeed_x; break;
    case 'r': spaceObjects_x += dt * spaceObjectsSpeed_x; break;
    case 'u': spaceObjects_y -= dt * spaceObjectsSpeed_y; break;
    case 'd': spaceObjects_y += dt * spaceObjectsSpeed_y; break;
    }
}

spaceObjects::~spaceObjects() {}
