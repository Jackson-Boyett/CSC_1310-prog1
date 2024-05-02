//this is the header file for the videoGame class

#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include "Text.h"
#include <fstream>
#include <iomanip>

using namespace std;

class VideoGame {

    private: 
    Text * title;
    Text * platforms;
    int year;
    Text * genre;
    Text * ageRating;
    int userRating;

    public:
    VideoGame(Text*, Text*, int, Text*, Text*, int);
    ~VideoGame();
    void printVideoGameDetails();                       //prototypes
    void printVideoGameDetailsToFile(ofstream&);
    Text* getVideoGameTitle();
};

#endif