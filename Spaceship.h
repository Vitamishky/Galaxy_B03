#ifndef Spaceship_hpp
#define Spaceship_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>

using namespace std;

class Spaceship {
public:
    Spaceship();
    Spaceship(sf::RenderWindow&);
    ~Spaceship();
    void moveship(char);
    void drawsprite(sf::RenderWindow&);
private:
    signed int ss_x, ss_y;
    unsigned int ss_speed;
    int ss_width, ss_height, ss_radius;

};
#endif /* Spaceship_hpp */
