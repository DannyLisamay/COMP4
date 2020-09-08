#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "LSFR.hpp"

int main(int argc, char* argv [])
{
    string inputImage, outputImage, seed, sTap;
    int tap;

    inputImage = argv[1];
    outputImage = argv[2];
    seed = argv[3];
    sTap = argv[4];
    tap = stoi(sTap);

    LSFR lsfr(seed, tap);
	sf::Image imageOrignal,imageEncoded;

	if (!imageOrignal.loadFromFile(inputImage))
		return -1;

	//   write the file
	if (!imageOrignal.saveToFile(outputImage))
		return -1;

    if (!imageEncoded.loadFromFile(outputImage))
		return -1; 

	// p is a pixel
	sf::Color p;

	// create encoded/decoded image
    	sf::Vector2u size = imageEncoded.getSize();
	for (int x = 0; x < (int)size.x; x++) {
		for (int y = 0; y < (int)size.y; y++) {
			p = imageEncoded.getPixel(x, y);
			p.r = lsfr.generate(8) ^ p.r;
			p.g = lsfr.generate(8) ^ p.g;
			p.b = lsfr.generate(8) ^ p.b;
			imageEncoded.setPixel(x, y, p);
		}
	}

	// write to save Encoded/Decoded
	if (!imageEncoded.saveToFile(outputImage))
		return -1;

	sf::RenderWindow windowOriginal(sf::VideoMode(size.x, size.y), "Original");
    sf::RenderWindow windowEncoded(sf::VideoMode(size.x, size.y), "Encoded/Decoded");

	sf::Texture textureOrignal, textureEncoded;
	textureOrignal.loadFromImage(imageOrignal);
    textureEncoded.loadFromImage(imageEncoded);

	sf::Sprite spriteOriginal, spriteEncoded;
	spriteOriginal.setTexture(textureOrignal);
    spriteEncoded.setTexture(textureEncoded);

	while (windowOriginal.isOpen() && windowEncoded.isOpen())
	{
		sf::Event event;
		while (windowOriginal.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				windowOriginal.close();
		}
        while (windowEncoded.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				windowEncoded.close();
		}

		windowOriginal.clear(sf::Color::White);
		windowOriginal.draw(spriteOriginal);
		windowOriginal.display();

		windowEncoded.clear(sf::Color::White);
		windowEncoded.draw(spriteEncoded);
		windowEncoded.display();
	}
;
	// implement make file
	// create read me

	return 0;
}