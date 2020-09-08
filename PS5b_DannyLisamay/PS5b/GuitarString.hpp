#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "RingBuffer.hpp"
using namespace std;

class GuitarString{
    public:
    GuitarString(double);
    GuitarString(vector<sf::Int16>);
    ~GuitarString();

    void pluck();
    void tic();
    sf::Int16 sample();
    int time();

    private:
    int ticks;
    RingBuffer* ptrRB;
};
