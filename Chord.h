//
// Created by Quin Scacheri on 11/2/17.
//

#ifndef UNTITLED1_CHORD_H
#define UNTITLED1_CHORD_H
#include<iostream>
#include<fstream>
#include <string>
using namespace std;

class Chord {
public:
    string root;
    int rootNum;

     Chord(string r);
    int note2Num(string  note);
};

#endif //UNTITLED1_CHORD_H


