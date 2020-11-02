#include <iostream>
#include <fstream>


#include "DSVector.h"
#include "DSString.h"
#include "WordPagePair.h"
#include <ctype.h>
#include <stdio.h>

using namespace std;


void orderedAdd(DSVector<WordPagePair>& vect, WordPagePair element){
    DSString phrase;
    phrase = element.getWord();
    DSString page = element.getPage();
    for(int k = 0;k < vect.getLength();k++){
        DSString temp = vect.at(k).getWord();
        if(!(phrase == temp)){
            if(phrase < temp){
                vect.insert(element, k);
                return;
            }
        } else {
            DSString tempPage = vect.at(k).getPage();
            if(page == tempPage)
                return;
            if(page < tempPage){
                vect.insert(element, k);
                return;
            }
        }
    }
    vect.push_back(element);
}

int main(int argc, char *argv[]) {

    DSVector<WordPagePair> *vect = new DSVector<WordPagePair>();

    //open all input and files
    ifstream input(argv[1]);
    ifstream keywords(argv[2]);
    ofstream output;
    output.open(argv[3]);


    //Check to see if file is open or not
    if (!input.is_open()) {
        cout << "Input: Error" << endl;
    }
    if (!keywords.is_open()) {
        cout << "Keyword: Error" << endl;
    }
    if (!output.is_open()) {
        cout << "Input: Error" << endl;
    }


     DSString* pageNum = new DSString();
    //Go through entire file
    while (!input.eof()) {
        DSString *line = new DSString();
        DSString::getline(input, *line);
        //Check to see if line has page number
        if (line->charAt(0) == '<') {
            delete pageNum;
            pageNum = new DSString();
            *pageNum = line->substring(1,line->size()-1);
        } else {
            //clean up all the punctuations and makes all words lowercase
            line->clean();
            DSVector<DSString> words;
            words = line->splitLine();
            //Store cleaned up words into vect
            for(int i = 0;i<words.getLength();i++) {
                WordPagePair *temp = new WordPagePair(*pageNum, words.at(i));
                //add WordPagePair into vector
                orderedAdd(*vect, *temp);
                delete temp;
            }
        }
        delete line;
    }
    DSString *keywordListTemp = new DSString();
    DSVector<DSString> *alphaOrder= new DSVector<DSString>();
    //loop through to store all the keywords and get them in alpha order
    while(!keywords.eof()) {
        DSString::getline(keywords, *keywordListTemp);
        if(!(*keywordListTemp == DSString("")))
            alphaOrder->orderedAdd(*keywordListTemp);
        delete keywordListTemp;
        keywordListTemp = new DSString();
    }

    char previousLetter = '0';
    //loop through to get the corresponding pages for the keywords
    for(int i = 0; i<alphaOrder->getLength();i++){
        DSVector<DSString> *pages = new DSVector<DSString>();
        for(int k = 0; k<vect->getLength();k++) {
            if (vect->at(k) == alphaOrder->at(i)) {
                pages->orderedAdd(vect->at(k).getPage());
            }
        }
        //loop through to add the index [X]
        if(toupper(alphaOrder->at(i).charAt(0))!=previousLetter){
            previousLetter=toupper(alphaOrder->at(i).charAt(0));
            output << " [" << previousLetter << "]" << endl;

        }
        //create entry to combine everything together to output onto file
        DSString *entry = new DSString();
        *entry+=alphaOrder->at(i);
        *entry+=": ";
        for(int k = 0; k<pages->getLength()-1;k++){
            *entry+=pages->at(k);
            *entry+=", ";
        }
        *entry+=pages->at(pages->getLength()-1);
        output << *entry<<endl;

    }
    output.close();
     return 0;
}
