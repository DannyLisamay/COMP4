#include "NBody.hpp"

 NBody::NBody(double xPos, double yPos, double xVel, double yVel, double mass, string fileName, sf::RenderWindow& window){
    this->xPos = xPos;
    this->yPos = yPos;
    this->xVel = xVel;
    this->yVel = yVel;
    this->mass = mass;
    texture.loadFromFile("./" + fileName);
    sprite.setTexture(texture);
    this->Draw(window);
}

void NBody::Draw (sf::RenderWindow& window){
    sprite.setPosition(xPos,yPos);
    window.draw(sprite);
}

int main(int argc, char* argv[]){
    int numOfParticals;
    double radiusOfUniverse;
    vector <NBody> vecNBody;
    cin >> numOfParticals >> radiusOfUniverse;
    double windowLength = radiusOfUniverse/5e+8 * 2, windowHeight = radiusOfUniverse/5e+8 *2;
    sf::RenderWindow window(sf::VideoMode(windowLength, windowHeight), "The Solar System");
    
    //extra credit draw background
    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromFile("./background.jpg");
    sprite.setTexture(texture);
    window.draw(sprite);

    
    for(int i = 0; i< numOfParticals; i++){
        double xPos, yPos, xVel, yVel, mass;
        string filename;
        //xPos scales and sets to center of "Universe"
        cin >> xPos;
        xPos /= 5e+8;
        xPos += radiusOfUniverse/5e+8;
        //yPos scales and sets to center of "Universe"
        cin >> yPos;
        yPos /= 5e+8;
        yPos += radiusOfUniverse/5e+8;
        //xVel scales
        cin >> xVel;
        xVel /= 5e+8;
        //yVel scales
        cin >> yVel;
        yVel /= 5e+8;
        //mass scales
        cin >> mass;
        mass /= 5e+8;
        //filename
        cin >> filename;
        
        //creates new nbody and pushes on to vector
        NBody nbody (xPos, yPos, xVel, yVel, mass, filename, window);
        vecNBody.push_back(nbody);
    }

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
    return EXIT_SUCCESS;
}