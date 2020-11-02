//
// Created by William Chan on 1/30/20.
//

#include <iostream>
#include <cstring>
#include <vector>

#ifndef S20_PA01_SENTIMENTANALYSIS_DSSTRING_H
#define S20_PA01_SENTIMENTANALYSIS_DSSTRING_H


class DSString {

public:

    DSString();
    DSString(const char*);
    DSString(const DSString&);
    ~DSString();
    DSString& operator=(const char*);
    bool operator== (const char*);
    bool operator== (const DSString&);
    static void getline (std::istream&,DSString&);
    DSString operator+(const char& character);
    DSString& operator+= (const char&);
    friend std::ostream& operator<< (std::ostream&, const DSString&);
    std::vector<DSString>* split(char delimiter);
    char charAt(int);
    int size();
    bool operator<(const DSString&) const;


private:
    char* data;
    static char buffer[1121];


};


#endif //S20_PA01_SENTIMENTANALYSIS_DSSTRING_H
