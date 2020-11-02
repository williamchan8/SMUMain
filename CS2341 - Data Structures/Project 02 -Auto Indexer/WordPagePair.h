//
// Created by William Chan on 2/29/20.
//

#ifndef INC_20S_PA02_WordPagePair_WordPagePair_H
#define INC_20S_PA02_WordPagePair_WordPagePair_H

#include <iostream>
#include "DSString.h"



using namespace std;


class WordPagePair {
    //declares the class methods
public:
    WordPagePair();
    WordPagePair(const DSString&,const DSString&);
    DSString getPage();
    DSString getWord();
    void setPage(int);
    void setWord(const DSString&);
    friend ostream& operator<<(ostream&, const WordPagePair&);
    bool operator== (const DSString&);
//declares the two variables
private:
    DSString page;
    DSString word;

};


#endif //INC_20S_PA02_WordPagePair_WordPagePair_H
