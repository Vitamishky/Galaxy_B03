#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Spaceship.h"
#include <vector>

int main(int, char const**)
{

    sf::RenderWindow window(sf::VideoMode(1960, 1200), "SpaceShuttle");
    window.setFramerateLimit(30);

    sf::Image icon;
    if (!icon.loadFromFile("space-shuttle.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Texture texture;
    if (!texture.loadFromFile("bg.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    Spaceship spaceship(window);
    sf::Clock sf_clock;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { spaceship.moveship('l'); }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { spaceship.moveship('r'); }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { spaceship.moveship('u'); }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { spaceship.moveship('d'); }

        }

        window.clear();

        window.draw(sprite);
        spaceship.drawsprite(window);

        window.display();
    }

    return EXIT_SUCCESS;
}
