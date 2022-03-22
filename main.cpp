#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "spaceObjects.h"
#include "camera.h"
#include "parametrizationScreen.h"
#include <vector>

int main()
{
    parametrizationScreen screen;
    //Отрисовка окна
    sf::RenderWindow window(sf::VideoMode(screen.getParametrizationScreen().first, 
                                          screen.getParametrizationScreen().second), "Galaxy-B03");
    //view.reset(sf::FloatRect(0, 0, 1900, 1050));

    window.setFramerateLimit(30);

    //Отрисовка иконки около названия окна
    sf::Image icon;
    if (!icon.loadFromFile("spaceShip.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Создание класса камеры
    //camera camera;

    //Отрисовка заднего фона
    sf::Texture texture;
    if (!texture.loadFromFile("bg.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite backWall(texture);
    
    spaceShip spaceship;

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

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                spaceship.moveShip(dt, 'l');
                //camera.getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                spaceship.moveShip(dt, 'r');
                //getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                spaceship.moveShip(dt, 'u');
                //getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                spaceship.moveShip(dt, 'd');
                //getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }
        }

        window.draw(backWall);

        //window.setView(view);

        spaceship.drawSprite(window);

        window.display();

        window.clear();
    }

    return EXIT_SUCCESS;
}
