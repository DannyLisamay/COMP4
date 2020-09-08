#include "NBody.hpp"

 NBody::NBody(double xPos, double yPos, double xVel, double yVel, double mass, string fileName, sf::RenderWindow& window,double radiusOfUniverse){
    this->xPos = xPos;
    this->yPos = yPos;
    this->xVel = xVel;
    this->yVel = yVel;
    this->mass = mass;
    this->fileName = fileName;
    this->radiusOfUniverse = radiusOfUniverse;
    texture.loadFromFile("./" + fileName);
    sprite.setTexture(texture);
}

void NBody::Draw (sf::RenderWindow& window){
    double xTemp, yTemp;
    //xPos scales and sets to center of "Universe"                              
    xTemp = xPos / 5e+8;
    xTemp += radiusOfUniverse/5e+8;
    //yPos scales and sets to center of "Universe"                              
    yTemp = yPos / 5e+8;
    yTemp += radiusOfUniverse/5e+8;
    //cout<< endl << fileName + ": "<< "xTemp = " << xTemp<<" "<< "yTemp = " << yTemp<<endl;
    sprite.setPosition(xTemp,yTemp); 
    window.draw(sprite);
}


//Part B 
//Getters
double NBody::GetXPos(){
    return xPos; 
}
double NBody::GetYPos(){
    return yPos;
}
double NBody::GetMass(){
    return mass;
}
string NBody::to_string(){
    string s = std::to_string(xPos) + " " + std::to_string(yPos) + " " + std::to_string(xVel) 
    + " " + std::to_string(yVel) + " " + std::to_string(mass) + " " + fileName;
    return s;
}

//Distance/Radius
double NBody::CalcRadius(NBody& nBody){
    return sqrt((pow((xPos - nBody.GetXPos()),2) + pow((yPos - nBody.GetYPos()),2)));
}

//Forces
double NBody::CalcPairwiseForce(NBody& nBody, double radius){
    double force = G* nBody.GetMass() * mass;
    return force/pow(radius,2);
}


double NBody::CalcForceXY(double delta, double radius, double pwForce){
    return pwForce*delta/radius;
}

double NBody::CalcDistance(double x, double y){ 
    return y-x;
}

void NBody::CalcVel(double deltaTim){
    xVel += (deltaTim * xAccel); 
    yVel += -(deltaTim * yAccel);
}

void NBody::CalcPos(double deltaTime){
    xPos += (deltaTime * xVel); 
    yPos += -(deltaTime * yVel);
}

void NBody::Step(double sec) {
    xAccel = xForce / mass;
    yAccel = yForce/ mass;
    CalcVel(sec);
    CalcPos(sec); 
}

int main(int argc, char* argv[]){
    sf::Font font;
    if (!font.loadFromFile("./Sans-Regular.ttf")) {
        return EXIT_FAILURE;
    }

    sf::Music music;
    if (!music.openFromFile("./music.ogg")) {
        return EXIT_FAILURE;
    }
    music.play();

    sf::Text text;
    text.setString("Elapsed Time: ");
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);

    int numOfParticals;
    double radiusOfUniverse;
    vector <NBody> vecNBody;
    cin >> numOfParticals >> radiusOfUniverse;
    double windowLength = radiusOfUniverse/5e+8 * 2, windowHeight = radiusOfUniverse/5e+8 *2;
    sf::RenderWindow window(sf::VideoMode(windowLength, windowHeight), "The Solar System");


    double totalTime;
    double deltaTime;
    double elapsedTime = 0;
    totalTime = stoi(argv[1]);
    deltaTime = stoi(argv[2]);

    //extra credit draw background
    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromFile("./background.jpg");
    sprite.setTexture(texture);
    window.draw(sprite);

    for(int i = 0; i< numOfParticals; i++){
        double xPos, yPos, xVel, yVel, mass;
        string filename;
        cin >> xPos;
        cin >> yPos;
        cin >> xVel;
        cin >> yVel;
        cin >> mass;
        cin >> filename;
        //creates new nbody and pushes on to vector
        NBody nbody (xPos, yPos, xVel, yVel, mass, filename, window,radiusOfUniverse);
        vecNBody.push_back(nbody);
    }
    double dx,dy,radius, force, netForceX, netForceY;
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
        if (elapsedTime < totalTime){
            window.clear();
            window.draw(sprite);
            text.setString("Elapsed Time: " + to_string(elapsedTime));

            for(NBody i: vecNBody){
                i.Draw(window);
                window.draw(text);
            }
            window.display();

            for (unsigned int i = 0 ; i < vecNBody.size(); i++){
                for (unsigned int j = 0 ; j < vecNBody.size(); j++){
                    if(i != j){
                        dx = vecNBody[i].CalcDistance(vecNBody[i].GetXPos(), vecNBody[j].GetXPos());
                        dy = vecNBody[i].CalcDistance(vecNBody[i].GetYPos(), vecNBody[j].GetYPos()); 
                        radius = vecNBody[i].CalcRadius(vecNBody[j]);
                        force = vecNBody[i].CalcPairwiseForce(vecNBody[j],radius);
                        netForceX += vecNBody[i].CalcForceXY(dx,radius,force);
                        netForceY += vecNBody[i].CalcForceXY(dy,radius,force);
                    }
                }
                vecNBody[i].xForce = netForceX;
                vecNBody[i].yForce = netForceY;
                netForceX = 0;
                netForceY = 0;
            }
            for (unsigned int i = 0 ; i < vecNBody.size(); i++){
                vecNBody[i].Step(deltaTime);
            }
            elapsedTime += deltaTime;
        }
    }
    return EXIT_SUCCESS;
}