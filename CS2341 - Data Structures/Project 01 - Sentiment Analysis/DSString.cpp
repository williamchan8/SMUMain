//
// Created by William Chan on 1/30/20.
//

#include "DSString.h"

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

DSString::~DSString() {
    delete[] data;
   // data = nullptr;

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
    if(strcmp(String.data, data) < 0){
        return true;
    }
    else{
        return false;
    }
}


