//this is the Header file for the text class

#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <cstring>

using namespace std;

class Text {
    
    private: 
    const char * textArray;
    int textLength;

    public:
    Text(const char*);
    ~Text();                    //prototypes

    void displayText();
    const char* getText();
    int getLength();
};

#endif