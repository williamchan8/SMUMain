#include <iostream>
#include <fstream>
#include "DSString.h"
#include "classifier.h"



int main(int argc, char *argv[]) {

    classifier tweet;

    std::ifstream input(argv[1]);
    std::ifstream target(argv[2]);

    tweet.train(input,target);

    std::cout<<"Finished with training."<<std::endl;

    input = std::ifstream (argv[3]);
    target = std::ifstream(argv[4]);

    tweet.test(input,target, argv[5]);


    return 0;
}
