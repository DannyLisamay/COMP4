#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
using namespace std;
class NBody{
    public:
    NBody(){};
    NBody(double xPos, double yPos, double xVel, double yVel,double mass, string fileName, sf::RenderWindow& window);

    private: 
    double xPos, yPos, xVel, yVel, mass;
    sf::Texture texture;
    sf::Sprite sprite;
    virtual void Draw (sf::RenderWindow& window);
};