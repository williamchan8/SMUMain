//
// Created by William Chan on 1/30/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_DSSTRING_H
#define S20_PA01_SENTIMENTANALYSIS_DSSTRING_H

#include <iostream>
#include <cstring>
#include <vector>
#include "DSVector.h"
#include <sstream>


class DSString {

public:

    DSString();
    DSString(const char);
    DSString(const char*);
    DSString(const DSString&);
    ~DSString();
    DSString& operator=(const char*);
    DSString& operator= (const DSString&);
    bool operator== (const char*);
    bool operator== (const DSString&);
    static void getline (std::istream&,DSString&);
    DSString operator+(const char& character);
    DSString& operator+= (const char&);
    DSString& operator+= (const DSString&);
    friend std::ostream& operator<< (std::ostream&, const DSString&);
    std::vector<DSString>* split(char delimiter);
    char charAt(int);
    int size();
    bool operator<(const DSString&) const;
    DSString substring(int a, int b);
    void clean ();
    DSString operator +(const DSString&);
    void erase(int x);
    DSVector<DSString> splitLine();

private:
    char* data;
    static char buffer[1121];
};


#endif //S20_PA01_SENTIMENTANALYSIS_DSSTRING_H
