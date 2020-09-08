#include "PTree.hpp"
PTree::PTree(int L, int N){
    sizeOfSquare = L;
    depthOfRecursion = N;
}

void PTree::pTree(sf::RenderTarget& window, sf:: RectangleShape& parent, int N, sf::Color C){
    //Used for 45-45-90 
    //float sizeFormula = sqrt(2.f) / 2; // new square size will be sqrt(2)/2

    //sizeFormula for 30-60-90 //Extra credit
    float sizeLeftFormula = sqrt(3.f)/2;
    float sizeRightFormula = 2;
    if (N<1) {
        return;
    }
    
    //Change color //Extra credit
    parent.setFillColor (C);
    C.r += 50;
    C.g += 20;
    C.b += 5;

    window.draw(parent);
    sf::Vector2f size = parent.getSize();
    auto transform = parent.getTransform();

    //Left children
    sf::RectangleShape leftChild = parent;
    //leftChild.setSize(size * sizeFormula);
    //leftChild.rotate(-45);
    //rotated differnt angle and size //Extra credit
    leftChild.setSize(size * sizeLeftFormula);
    leftChild.rotate(-30);
    leftChild.setOrigin(0, leftChild.getSize().y);
    leftChild.setPosition(transform.transformPoint(0,0));
    

    pTree(window, leftChild, N-1, C);

    //Right children
    sf::RectangleShape rightChild = parent;
    //rightChild.setSize(size * sizeFormula);
    //rightChild.rotate(45);
    //rotated differnt angle and size //Extra credit
    rightChild.setSize(size / sizeRightFormula);
    rightChild.rotate(60);
    rightChild.setOrigin(rightChild.getSize());
    rightChild.setPosition(transform.transformPoint(size.x,0));

    pTree(window, rightChild, N-1, C);    
} 

int main(int argc, char* argv[]){
    int L = stoi(argv[1]);
    int N = stoi(argv[2]);
    int windowLength = 8 * L;
    int windowHeight = 6 * L;
    PTree ptree(L, N);

    sf::RenderWindow window(sf::VideoMode(windowLength, windowHeight), "Pythagoras Tree");
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
        // Clear screen
        window.clear(sf::Color(255,255,225));
        // Draw the pythagros tree 
        // BaseSquare
        sf::RectangleShape baseSquare(sf::Vector2f(L, L));
        baseSquare.setPosition(L *4, L *4);
        sf::Color color (0, 0, 50);

        // Recusivly draw tree
        ptree.pTree(window, baseSquare, N, color);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
    
}