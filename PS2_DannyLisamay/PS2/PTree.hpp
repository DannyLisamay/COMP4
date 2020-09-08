#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>
using namespace std;
class PTree{
    public:
    PTree(int L, int N);
    void pTree(sf::RenderTarget& window, sf:: RectangleShape& parent, int N, sf::Color C);
    sf::RectangleShape getSquare();

    private:
    int sizeOfSquare;
    int depthOfRecursion;
};