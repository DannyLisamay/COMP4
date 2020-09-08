/*
  Copyright 2015 Fred Martin, fredm@cs.uml.edu
  Edited: Dheera Vuppala and Danny Lisamay
  Mon Mar 30 08:58:49 2015

  based on Princeton's GuitarHeroLite.java
  www.cs.princeton.edu/courses/archive/fall13/cos126/assignments/guitar.html

  build with
  g++ -Wall -c GuitarHeroLite.cpp -lsfml-system \
     -lsfml-audio -lsfml-graphics -lsfml-window
  g++ -Wall GuitarHeroLite.o RingBuffer.o GuitarString.o \
   -o GuitarHeroLite -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window
*/
#include <math.h>
#include <limits.h>

#include <string>
#include <exception>
#include <stdexcept>

#include "GuitarString.hpp"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

vector<sf::Int16> makeSamplesFromString(GuitarString& gs) {
  std::vector<sf::Int16> samples;

  gs.pluck();
  int duration = 8;  // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }

  return samples;
}

int main() {
  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Guitar Hero");
  sf::Event event;
  double freq;
  string s = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
  vector<vector<sf::Int16>> samples(37);
  vector<sf::SoundBuffer> soundBuffer(37);
  vector<sf::Sound> sounds(37); 

  // we're reusing the freq and samples vars, but
  // there are separate copies of GuitarString, SoundBuffer, and Sound
  //   for each note
  //
  // GuitarString is based on freq
  // samples are generated from GuitarStrin
  // SoundBuffer is loaded from samples
  // Sound is set to SoundBuffer
    for(int i = 0; i < 37; i++){
        freq = CONCERT_A +(i * pow(2, 3.0/12.0));
        GuitarString gs1 = GuitarString(freq);
        samples[i] = makeSamplesFromString(gs1);
        if(!soundBuffer[i].loadFromSamples(&samples[i][0], samples[i].size(), 2, SAMPLES_PER_SEC))
             throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
        sounds[i].setBuffer(soundBuffer[i]);
    }
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
        window.close();
    for(auto i=0; i<37; i++) { 
        if(event.type == sf::Event::TextEntered) { 
            if(event.text.unicode == (unsigned int)s[i])
            { 
                sounds[i].play();
            }
        }
    }
    window.clear();
    window.display();
    }
  }
  return 0;
}
