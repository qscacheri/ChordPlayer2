//
// Created by Quin Scacheri on 11/2/17.
//



#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Min.h"
#include "Chord.h"

using namespace std;


Min::Min(string root) : Chord(root) {

    noteArray[0] = rootNum;
    noteArray[1] = findThird(rootNum);
    noteArray[2] = findFifth(rootNum);
}

Min::Min(string root, string sus) : Chord(root) {

    string rootLetter = root;
    suspensions = findNumOfSus(sus);
    NUMNOTES += suspensions;

    noteArray = new int[NUMNOTES];
    noteArray[0] = rootNum;
    noteArray[1] = findThird(rootNum);
    noteArray[2] = findFifth(rootNum);
    noteArray[3] = 0;
    noteArray[4] = 0;
    noteArray[5] = 0;
    cout << noteArray[1] << "na" << endl;
    findSusNums(sus);
}

int Min::findThird(int root) {
    if (rootNum + 4 > 11) {
        return rootNum - 8;
    } else
        return rootNum + 4;
}

int Min::findFifth(int root) {
    if (rootNum + 7 > 12) {
        return rootNum - 5;
    } else
        return rootNum + 7;
}

int Min::findNumOfSus(string s) {
    int counter = 1;
    std::string s1 = s;
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    while ((pos = s1.find(delimiter)) < std::string::npos) {
        token = s1.substr(0, pos);
//        std::cout << token << std::endl;
        s1.erase(0, pos + delimiter.length());
        counter++;
    }
    //std::cout << counter << ("asdfsfd");
    return counter;
}

void Min::findSusNums(string s) {
//    cout << "i hate c++" << std::endl;
    int mod;
    string temp = "";
    int tempNum;
    int susCounter = 3;
    string susArray[suspensions];
    int arrayCounter = 0;

    //MAKES ARRAY OF SUSPENSIONS
    std::istringstream ss(s);
    std::string token;

    while (std::getline(ss, token, ',')) {
        susArray[arrayCounter] = token;
        arrayCounter++;
    }

//    cout << suspensions << endl;
    for (int i = 0; i < suspensions; i++) {
//        cout << i << "<i" << endl;
        tempNum = 0;
        temp = "";
        int startPoint;
//        cout<<susArray[i].length()<<endl;
        if (susArray[i].at(0) == 'b' || susArray[i].at(0) == '#')
            startPoint = 1;
        else startPoint = 0;

        for (int k = startPoint; k < susArray[i].length(); k++) {
            temp += susArray[i].at(k);
            tempNum = std::stoi(temp);
//            cout << tempNum << " c" << endl;
        }


        if (susArray[i].at(0) == 'b')
            mod = -1;


        else if (susArray[i].at(0) == '#')
            mod = 1;

        else
            mod = 0;

        cout << "mod is: " << mod << endl;


        if (tempNum == 7) {
            if (mod + rootNum + 11 > 11) {
                tempNum = rootNum - 1 - mod;
            } else
                tempNum = rootNum + 11 + mod;
        } else if (tempNum == 9) {
            if (rootNum + 2 + mod > 11) {
                tempNum = rootNum - 10 - mod;
            } else
                tempNum = rootNum + 2 + mod;
        } else if (tempNum == 11) {
            if (rootNum + 5 + mod > 11) {
                tempNum = rootNum - 7 - mod;
            } else
                tempNum = rootNum + 5 + mod;
        } else if (tempNum == 13) {
            //System.out.println(rootNum);
            if (rootNum + 9 + mod > 11) {
                tempNum = rootNum - 3 - mod;
            } else {
                tempNum = rootNum + 9 + mod;
            }

        }
//        cout << noteArray[0] << "temp num" << endl;
        noteArray[susCounter] = tempNum;
        susCounter++;
    }

}


string Min::toString() {
    return rootLetter;
}

void Min::getNoteNums() {
    for (int i = 0; i < NUMNOTES; i++) {
        cout << (noteArray[i]) << "\n" << std::endl;

    }
}