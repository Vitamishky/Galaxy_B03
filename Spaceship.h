#ifndef spaceShip_hpp
#define spaceShip_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>

using namespace std;

class spaceShip {
private:
    float ss_x, ss_y;
    float ss_speed_x, ss_speed_y;
    int ss_width, ss_height;
    sf::Sprite ss_sprite;
    sf::Texture ship;
public:
    spaceShip();
    spaceShip(sf::RenderWindow&);
    ~spaceShip();
    void moveShip(float, char);
    void drawSprite(sf::RenderWindow&);
};

#endif 
