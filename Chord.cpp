//
// Created by Quin Scacheri on 11/2/17.
//

#include "Chord.h"
#include<iostream>
#include<fstream>
#include <string>
using namespace std;


Chord::Chord(string r) {
    root = r;
    rootNum = note2Num(root);
}

int Chord::note2Num(string note){
    int noteNum = 0;

    if (note == "C")
        noteNum = 0;
    else if (note == "C#" || note == "Db")
        noteNum = 1;
    else if (note == "D")
        noteNum = 2;
    else if (note == "D#" || note == "Eb")
        noteNum = 3;
    else if (note == "E")
        noteNum = 4;
    else if (note == "F")
        noteNum = 5;
    else if (note == "F#" || note == "Gb")
        noteNum = 6;
    else if (note == "G")
        noteNum = 7;
    else if (note == "G#" || note == "Ab")
        noteNum = 8;
    else if (note == "A")
        noteNum = 9;
    else if (note == "A#" || note == "Bb")
        noteNum = 10;
    else if (note == "B")
        noteNum = 11;
    return noteNum;
}