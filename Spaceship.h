#ifndef spaceShip_hpp
#define spaceShip_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>

using namespace std;

class spaceShip {
private:
    float spaceShip_x, spaceShip_y;
    float spaceShipSpeed_x, spaceShipSpeed_y;
    int spaceShipWidth, spaceShipHeight;
    sf::Sprite spaceShipSprite;
    sf::Texture textureShip;
public:
    spaceShip();
    spaceShip(sf::RenderWindow&);
    ~spaceShip();
    void moveShip(float, char);
    void drawSprite(sf::RenderWindow&);
};

#endif 
