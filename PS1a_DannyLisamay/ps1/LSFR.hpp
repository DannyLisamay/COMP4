#pragma once
#include <iostream>
#include <math.h>
using namespace std;
class LSFR{
public:
    LSFR();
    LSFR(string s, int t);

    int step();

    int generate(int k);

    void toString();

private:
    string seed;
    int tap;    
    int seedArr[32];
};