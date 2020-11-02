//
// Created by William Chan on 2/3/20.
//


#include "classifier.h"
#include "DSString.h"
#include <map>


#include <fstream>


void classifier::train(std::ifstream& trainData, std::ifstream& trainTarget) {

    DSString* train = new DSString();
    DSString* targetNum = new DSString();
    DSString::getline(trainTarget,*targetNum); //take out first row key
    DSString::getline(trainData,*train);        //take out first row key
    while(!trainData.eof()){
        DSString::getline(trainTarget,*targetNum);
        DSString::getline(trainData, *train);
        if(train->size()>0) {
            std::vector<DSString> *groups = train->split(','); //Split to get the text
            std::vector<DSString> *groupsTarget = targetNum->split(','); //Split to get the text
            //if not precise enough check group 3 and later

            std::vector<DSString> *words = groups->at(3).split(' '); //From each line, get single word
            for (int i = 0; i < words->size(); i++) {
                if (!(words->at(i) == "")) {
                    if (groupsTarget->at(1) == "4") {
                        int tempcount = happyCount[words->at(i)];
                        happyCount[words->at(i)] = tempcount + 1;
                    } else {
                        int tempSad = sadCount[words->at(i)];
                        sadCount[words->at(i)] = tempSad + 1;

                    }
                }
            }
            delete train;
            delete targetNum;
            train = new DSString();
            targetNum = new DSString();

            delete groups;
        }
    }

}

void classifier::test(std::ifstream& input, std::ifstream& target, const char* file){

    DSString* test = new DSString();
    DSString* trial = new DSString();
    DSString::getline(input,*test);

    DSString::getline(target,*trial);
    std::vector<DSString> wrongID; //Vector to hold wrong IDs

    delete test;

    int numCorrect;
    int totalFinal;

    //while(!input.eof())
    for(int i = 0;i<10000;i++){

        test=new DSString();
        trial = new DSString();
        DSString::getline(input, *test);
        std::vector<DSString> *testGroup = test->split(',');
        std::vector<DSString> *testWords = testGroup->at(3).split(' ');

        DSString::getline(target,*trial);
        std::vector<DSString> *targetNums = trial->split(',');

        //std::cout<<"the heck "<<testGroup->at(3)<<std::endl;
        double total = 0;
        for (int i = 0;i<testWords->size();i++){


            double happyWords = happyCount[testWords->at(i)];
            double sadWords = sadCount[testWords->at(i)];

            if(happyWords+sadWords != 0) {
                if (happyWords > sadWords) {

                    total += (happyWords - sadWords) / (happyWords + sadWords);


                } else {
                    total -= (sadWords - happyWords) / (happyWords + sadWords);

                }
            }

        }

        bool isPositive;
        if ((total > 0 && targetNums->at(1) == "0")||(total <= 0 && targetNums->at(1) == "4")){

            wrongID.push_back(targetNums->at(2));

        }else{
            numCorrect++;
        }
            totalFinal++;

        if(totalFinal%100 == 0)
            std::cout << numCorrect << "," << totalFinal << " = " << (double)(numCorrect)/totalFinal << std::endl;

        delete test;
        delete trial;
    }

        double total = (double)(numCorrect)/totalFinal;
        std::cout<<"This is the percent "<<total<<std::endl;

        std::ofstream output;
        output.open(file);




        output<<total<<'\n'<<std::endl;
        for(int i = 0;i<wrongID.size();i++){
            output<<wrongID.at(i)<<std::endl;
        }

        output.close();


}
