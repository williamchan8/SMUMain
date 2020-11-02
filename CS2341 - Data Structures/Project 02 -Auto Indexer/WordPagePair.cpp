//
// Created by William Chan on 2/29/20.
//

#include "WordPagePair.h"


//default constructor for an WordPagePair
WordPagePair::WordPagePair(){
    page = "";
    word = "";
}

//overloaded constructor for an WordPagePair with the word or phrase and the page it can be found on
WordPagePair::WordPagePair(const DSString& tPage, const DSString& tWord){
    page = tPage;
    word = tWord;
}

//returns the page of the word/phrase
DSString WordPagePair::getPage(){
    return page;
}

//returns teh word or phrase
DSString WordPagePair::getWord(){
    return word;
}

//sets the page containing the word or phrase
void WordPagePair::setPage(int tPage){
    page = tPage;
}

//sets the word or phrase
void WordPagePair::setWord(const DSString& tWord){
    word = tWord;
}

//allows for the WordPagePair to be displayed to the screen
ostream& operator<<(ostream& os, const WordPagePair& in){
    os << in.word << " - " << in.page;
    return os;
}
//allows wordpagepair to use == with DSString and word
bool WordPagePair::operator==(const DSString& String){
    //if(strcmp(String.data, word) == 0)
    if(this->getWord()== DSString(String)){
        return true;
    }
    else{
        return false;
    }
}

