#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main()
{
    //Position Variiables
    int xCoord = 200;
    int yCoord = 200;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "SFML window");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("./sprite.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    // Start the loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            
            // Move Spirte
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                // move left...
                xCoord--;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                // move right...
                xCoord++;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                // move up...
                yCoord--;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                // move down...
                yCoord++;
            }

            //Rotate image
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                sprite.rotate(45);
            }

        }
        // Clear screen
        window.clear();
        // Draw the sprite
        sprite.setPosition(xCoord,yCoord);
        window.draw(sprite);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}