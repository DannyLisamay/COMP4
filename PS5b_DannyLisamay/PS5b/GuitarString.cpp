#include "GuitarString.hpp"
#include "math.h"

GuitarString::GuitarString(double freq){
    int size = ceil(44100/freq); 
    ptrRB = new RingBuffer(size); 
    while(ptrRB->isFull()==false) { 
        ptrRB->enqueue(0); 
    }
    ticks = 0; 
}
GuitarString::GuitarString(vector<sf::Int16> init){
   
    ptrRB = new RingBuffer(init.size()); 
    int x=0; 
    while(ptrRB->isFull()==false) { 
        ptrRB->enqueue(init[x]); 
        x++; 
    }
    ticks = 0; 
}

GuitarString::~GuitarString(){
    delete ptrRB; 
}

void GuitarString::pluck(){
    
    if(ptrRB->isFull()==true) { 
        for (int i=0; i<ptrRB->size(); i++) { 
            ptrRB->dequeue(); 
        }
    }

    while(ptrRB->isFull()==false) { 
         auto random = []() {
        return (rand() % 32767) - 32767; 
    };
        ptrRB->enqueue((sf::Int16)random()); 
    }
}
void GuitarString::tic(){
    sf::Int16 x = 0.996 * (ptrRB->dequeue() + ptrRB->peek()); 
    x/=2;
    ptrRB->enqueue(x); 
    ticks++; 
}
sf::Int16 GuitarString::sample(){
    return ptrRB->peek();
}
int GuitarString::time(){
    return ticks;
}