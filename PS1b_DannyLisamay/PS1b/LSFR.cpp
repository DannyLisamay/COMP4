#include "LSFR.hpp"

LSFR::LSFR(string s, int t){
    seed = s;
    tap = t;
    for(unsigned int i =0; i < seed.size(); i++){
        seedArr[i] = (int)(seed[seed.size() - i -1]) -48;
    }
}

int LSFR::step(){
    int tapBit = 0;

    if (seedArr[tap] != (seedArr[seed.size()-1])){
        tapBit = 1;
    }

    for(unsigned int i = seed.size(); i > 0; i--){
        seedArr[i+1] = seedArr[i];
    }
    seedArr[1] = seedArr[0];
    seedArr[0] = tapBit;

    return tapBit;
}

int LSFR::generate(int k){
    int kBitInt = 0;
    for (int i = 0; i < k; i++){
        if(step()){
            kBitInt += pow(2,i);
        }
    }
        return kBitInt;
}

void LSFR::toString(){
    for(unsigned int i =0; i < seed.size(); i++)
    {
        cout << seedArr[i];
    }
    cout << endl;
}