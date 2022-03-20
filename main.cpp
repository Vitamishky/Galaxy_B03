#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include <vector>

int main()
{

    sf::RenderWindow window(sf::VideoMode(1900, 1100), "Galaxy-B03", sf::Style::Fullscreen);
    window.setFramerateLimit(30);
    
    sf::Image icon;
    if (!icon.loadFromFile("spaceShip.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Texture texture;
    if (!texture.loadFromFile("bg.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite backWall(texture);

    spaceShip spaceship(window);

    sf::Clock sf_clock;

    while (window.isOpen()) {

        sf::Event event;

        float dt = sf_clock.restart().asSeconds();

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) spaceship.moveShip(dt, 'l');
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) spaceship.moveShip(dt, 'r');
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) spaceship.moveShip(dt, 'u');
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) spaceship.moveShip(dt, 'd');
        }

        window.draw(backWall);

        spaceship.drawSprite(window);

        window.display();

        window.clear();
    }

    return EXIT_SUCCESS;
}
