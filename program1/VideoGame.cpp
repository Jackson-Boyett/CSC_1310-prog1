#include "VideoGame.h"

//constructor
VideoGame::VideoGame(Text * title, Text * platforms, int year, Text * genre, Text * ageRating, int userRating) {
    this-> title = title;
    this-> platforms = platforms;
    this-> year = year;
    this-> genre = genre;
    this-> ageRating = ageRating;
    this-> userRating = userRating;
}

//destructor 
VideoGame::~VideoGame() {

    if(title != nullptr) {
        delete title;
    }
    
    if(platforms != nullptr) {
        delete platforms;
    }

    if(genre != nullptr) {
        delete genre;

    }

    if(ageRating != nullptr) {
        delete ageRating;

    }

    cout << "Released memory for title, platform, genre, & age rating." << endl;
}

//prints game details and uses the display text function from the Text class
void VideoGame::printVideoGameDetails() {
    cout << "\n";
    cout << setw(29) << "Game Title:  ";
    this->title->displayText();

    cout << "\n";
    cout << setw(29) << "Platform:  ";
    this->platforms->displayText();

    cout << "\n";
    cout << setw(29) << "Year Released:  ";
    cout << year << endl;

    cout << setw(29) << "Genre:  ";
    this->genre->displayText();
    cout << "\n";

    cout << setw(29) << "Rating:  ";
    this->ageRating->displayText();
    cout << "\n";

    cout << setw(29) << "Number of stars:  ";
    cout << userRating << endl;

}

//does the same thing as the printVideoGameDetails function except this is into a file named by the user
void VideoGame::printVideoGameDetailsToFile(ofstream& outFile) {

    outFile << this->title->getText() << "\n";

    outFile << this->platforms->getText() << "\n";

    outFile << year << endl;

    outFile << this->genre->getText() << "\n";

    outFile << this->ageRating->getText() << "\n";

    outFile << userRating << endl;
}

//accessor
Text* VideoGame::getVideoGameTitle() {
    return title;
}