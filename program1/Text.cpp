#include "Text.h"

//constructor
Text::Text(const char * textArray) {
    textLength = strlen(textArray);

    char * newTextArray = new char [textLength + 1];

    strcpy(newTextArray, textArray);

    this->textArray = newTextArray;
}

//destructor
Text::~Text() {
    delete [] textArray;

    cout << "Text destructor: Released memory for textArray." << endl;

}

//displays the cstrings. is called in other functions
void Text::displayText() {
    //checks for null ptr and returns if true
    if(textArray == nullptr) {
        return;
    }

    for(int i = 0; i < textArray[i] != '\0'; i++) {
        cout << textArray[i];
    }
}

//accessor
const char* Text::getText() {
    return textArray;
}

//accessor
int Text::getLength() {
    return textLength;
}