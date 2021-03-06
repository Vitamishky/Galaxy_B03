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
    
    window.setFramerateLimit(30);
    window.setVerticalSyncEnabled(true);

    //Отрисовка иконки около названия окна
    sf::Image icon;
    if (!icon.loadFromFile("spaceShip.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Отрисовка заднего фона
    sf::Texture texture;
    if (!texture.loadFromFile("bg.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite backWall(texture);
    
    //Создание космического корабля
    spaceShip spaceship;

    //Работа с камерой слежения
    camera camera(window);
    camera.resetView();

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
                camera.getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                spaceship.moveShip(dt, 'r');
                camera.getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                spaceship.moveShip(dt, 'u');
                camera.getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                spaceship.moveShip(dt, 'd');
                camera.getCoordinatesForView(spaceship.getCoordinates().first, spaceship.getCoordinates().second);
            }

            if (event.type == sf::Event::MouseMoved) {
                camera.moveCamera(event.mouseMove.x, event.mouseMove.y);
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                camera.lockedCamera(event.mouseButton.x, event.mouseButton.y);
            }
            
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                camera.unlockCamera();
            }
        }

        window.draw(backWall);

        window.setView(camera.getViewCamera());

        spaceship.drawSprite(window);

        window.display();

        window.clear();
    }

    return EXIT_SUCCESS;
}
