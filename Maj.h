//
// Created by Quin Scacheri on 11/2/17.
//
#ifndef UNTITLED1_MAJ_H
#define UNTITLED1_MAJ_H

#include<iostream>
#include<fstream>
#include <string>
#include "Chord.h"

using namespace std;

class Maj : public Chord {
public:

    int *noteArray;
    int NUMNOTES = 3;
    char sharp = '#';
    int suspensions;
    Maj(string r);

    Maj(string r, string sus);

    void getNoteNums();

    int* getNoteArray();

    int getNoteInArray(int i);

    int findThird(int root);

    int findFifth(int root);

    void getNumNotes();

    int getNumNotesInt();

    string toString();

    int findNumOfSus(string s);

    void findSusNums(string s);

    string rootLetter;
};


#endif //UNTITLED1_ASDF_H