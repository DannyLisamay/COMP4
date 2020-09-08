#pragma once
#include <SFML/System.hpp>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class ED{
    public:
    ED(string, string);
    static int penalty(char, char);
    static int min(int, int ,int);
    int OptDistance();
    string Alignment();

    private:
    vector <char> vecA;
    vector <char> vecB;
    vector <vector <int>> vecMatrix;
};