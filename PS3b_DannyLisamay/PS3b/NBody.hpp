#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <cmath>
#include <SFML/Audio.hpp>
using namespace std;
class NBody{
    public:
    double xForce = 0;
    double yForce = 0;
    NBody(){};
    NBody(double xPos, double yPos, double xVel, double yVel,double mass, string fileName, sf::RenderWindow& window,double radiusOfUniverse);
    virtual void Draw (sf::RenderWindow& window);

    //part B
    //Getter
    double GetXPos();
    double GetYPos();
    double GetMass();
    string to_string();

    double CalcPairwiseForce(NBody& nBody, double radius);
    double CalcRadius(NBody& nBody);
    double CalcForceXY(double, double, double);
    void Step(double sec);
    double CalcDistance(double, double);

    private: 
    string fileName;
    sf::Texture texture;
    sf::Sprite sprite;
    double radiusOfUniverse;
    double xPos, yPos, xVel, yVel, mass; 
    double xAccel = 0;
    double yAccel = 0;
    double G = 6.67e-11;

    void CalcVel(double deltaTime);
    void CalcPos(double deltaTime);
};