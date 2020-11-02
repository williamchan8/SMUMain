//
// Created by William Chan on 1/30/20.
//

#include "DSString.h"
#include <string>
#include <string.h>
#include <stdio.h>


DSString::DSString(){
    data = new char[1];
    data[0]='\0';

}

DSString::DSString(const char* string){
    data = new char[strlen(string) + 1];
    strcpy(data, string);
}

DSString::DSString(const DSString& String){
    data = new char[strlen(String.data) + 1];
    strcpy(data, String.data);
}

DSString::DSString(const char x){
    data = new char[1];
    data[0]=x;
}

DSString::~DSString() {
    if(data!=nullptr)
    delete[] data;
    data = nullptr;
}

std::ostream& operator<<(std::ostream& stream, const DSString& String){
    return stream << String.data;
}

DSString& DSString::operator=(const char* string){
    delete[] data;
    data = new char[strlen(string) + 1];
    strcpy(data, string);
    return *this;
}

DSString& DSString::operator=(const DSString& String){
    //delete[] data;
    data = new char[strlen(String.data) + 1];
    strcpy(data, String.data);
    return *this;
}

void DSString::getline(std::istream& file, DSString & string) {

        char ch;
        file.get(ch);
        while(ch!='\n' && !file.eof()){
            string += ch;
            file.get(ch);

        }
}



DSString DSString::operator+(const char& character){
    char* new_string = new char[strlen(data) + 2];
    strcpy(new_string, data);
    new_string[strlen(data)] = character;
    new_string[strlen(data) + 1] = '\0';
    DSString new_String = DSString(new_string);
    return new_String;
}

DSString& DSString::operator+=(const char& character){
    char* temp = data;
    int length = strlen(data);
    data = new char[strlen(data) + 2];
    strcpy(data, temp);
    data[length] = character;
    data[length + 1] = '\0';
    delete[] temp;
    return *this;
}
DSString& DSString::operator+=(const DSString& String){
    char* temp = data;
    data = new char[strlen(data) + strlen(String.data) + 1];
    strcpy(data, temp);
    strcat(data, String.data);
    delete[] temp;
    return *this;
}

std::vector<DSString>* DSString::split( char delimiter) {

    int index = 0;
    DSString *temp = new DSString();
    std::vector<DSString> *groups = new std::vector<DSString>();
    char ch = data[index];

        while (index != this->size()) {
            index++;
            if (ch == delimiter) {
                DSString onetime(*temp);
                groups->push_back(onetime);
                delete temp;
                temp = new DSString();
            } else {
                *temp += ch;
            }
            ch = data[index];
        }
        DSString onetime(*temp);
        groups->push_back(onetime);
         delete temp;
        return groups;
    }


char DSString::charAt(int x) {
    return data[x];
}

int DSString::size(){
    return strlen(data);
}
bool DSString::operator==(const char* string){
    if(strcmp(string, data) == 0){
        return true;
    }
    else{
        return false;
    }
}
bool DSString::operator==(const DSString& String){
    if(strcmp(String.data, data) == 0){
        return true;
    }
    else{
        return false;
    }
}
bool DSString::operator<(const DSString& String) const{
    if(strcmp(String.data, data) > 0){
        return true;
    }
    else{
        return false;
    }
}

DSString DSString::substring(int a, int b){
    char* string = new char[b-a];
    if(b >= 0){
        for(int i = 0; i < b-a; i++){
            string[i] = data[a + i];
        }
    }
//    if(b < 0){
//        for(int i = 0; i > b; i--){
//            string[i] = data[a - b - i];
//        }
//    }
    DSString temp = DSString(string);
    delete[] string;
    return temp;
}

 void DSString::clean(){
    int length = this->size();
    for(int k = 0; k < length; k++){
        if(ispunct(data[k])){
            if(!(data[k] == '+' || data[k] == '-')){
                erase(k);
                k -= 1;
                length -= 1;
            }
        } else {
            if(data[k] == ' '){
                if(k == 0){
                    erase(k);
                    k -= 1;
                    length -= 1;
                } else {
                    if(data[k-1] == ' '){
                        erase(k);
                        k -= 1;
                        length -= 1;
                    }
                }
            } else {
                data[k] = tolower(data[k]);
            }
        }
    }
}
DSString DSString::operator+(const DSString& String){
    char* new_string = new char[strlen(data) + strlen(String.data) + 1];
    strcpy(new_string, data);
    strcat(new_string, String.data);
    DSString new_String = DSString(new_string);
    delete[] new_string;
    return new_String;
}

void DSString::erase(int x){
    int length=strlen(data);
    char * temp_string =  new char[length];
    for(int i =0;i<length-1;i++){
        if(i<x){
            temp_string[i] = data[i];
        }
        else{
            temp_string[i] = data[i+1];
        }
    }
    temp_string[length-1] = '\0';
    delete data;
    data = temp_string;

}

DSVector<DSString> DSString::splitLine(){
    DSVector<DSString> end;
    DSString temp;
    char* splitter;
    splitter = strtok (data," ");
    while(splitter != NULL){
        temp = splitter;
        end.push_back(temp);
        splitter = strtok(NULL," ");
    }
    return end;
}
