//
// Created by William Chan on 2/3/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_CLASSIFIER_H
#define S20_PA01_SENTIMENTANALYSIS_CLASSIFIER_H


#include <istream>
#include <map>
#include "DSString.h"

class classifier {

public:
    void train(std::ifstream&, std::ifstream&);
    void test(const char*);
    void test(std::ifstream&, std::ifstream&, const char*);

private:
    std::map<DSString, int> happyCount;
    std::map<DSString, int> sadCount;

};


#endif //S20_PA01_SENTIMENTANALYSIS_CLASSIFIER_H
