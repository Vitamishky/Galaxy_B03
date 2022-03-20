#ifndef spaceObjects_hpp
#define spaceObjects_hpp
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>

using namespace std;

class spaceObjects {
private:
    float spaceObjects_x, spaceObjects_y;
    float spaceObjectsSpeed_x, spaceObjectsSpeed_y;
    int spaceObjectsWidth, spaceObjectsHeight;
    sf::Sprite spaceObjectsSprite;
    sf::Texture textureObjects;
public:
    spaceObjects();
    spaceObjects(sf::RenderWindow&);
    ~spaceObjects();
    void moveObjects(float, char);
    void drawSprite(sf::RenderWindow&);
};

#endif 

