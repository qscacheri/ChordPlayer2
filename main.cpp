#include <iostream>
#include"Chord.h"
#include"Maj.h"

int main() {
    Chord a("C");
    Maj C("C", "b7,9,#11");
    C.getNoteNums();
//    cout<<"hey"<<endl;
    return 0;
}