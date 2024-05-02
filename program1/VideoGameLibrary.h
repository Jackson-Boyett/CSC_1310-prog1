//This is the header file for the VideoGameLibrary class

#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include <iostream>
#include "Text.h"
#include "VideoGame.h"
#include <fstream>
#include <iomanip>

class VideoGameLibrary {

    private: 
    VideoGame ** videoGamesArray;
    int maxGames;
    int numGames;

    public:

    VideoGameLibrary(int);
    ~VideoGameLibrary();

    void resizeVideoGameArray();
    void addVideogameToArray();
    void displayVideoGames();                   //prototypes
    void displayVideoGameTitles();
    void loadVideoGamesFromFile(const char*);
    void removeVideoGameFromArray();
    void saveToFile(string);
};

#endif