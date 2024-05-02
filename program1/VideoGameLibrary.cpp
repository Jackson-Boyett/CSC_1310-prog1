#include "VideoGameLibrary.h"

//constructor
VideoGameLibrary::VideoGameLibrary(int maxGames) {
    this->maxGames = maxGames;
    videoGamesArray = new VideoGame* [maxGames];
    this->numGames = 0;
}

//destructor
VideoGameLibrary::~VideoGameLibrary() {

    for(int i = 0; i < numGames; i++) {
        if (videoGamesArray[i] != nullptr) {
            delete videoGamesArray[i];
        }
    }

    delete [] videoGamesArray;

    cout << "VideoGameLibrary destructor: Released memory for each game in the video game array itself." << endl;
}

//resizes the video game array by doubling it
void VideoGameLibrary::resizeVideoGameArray() {

    int newMaxGames =  maxGames * 2;

    cout << "resizing videogames array from " << maxGames << " to " << newMaxGames << endl;

    VideoGame ** newVideoGamesArray = new VideoGame*[newMaxGames];

    for(int i = 0; i < numGames; i++) {
        newVideoGamesArray[i] = videoGamesArray[i];
    }

    delete [] videoGamesArray;

    this-> videoGamesArray = newVideoGamesArray;
    this-> maxGames = newMaxGames;

}

//adds a new video game to the library after the user inputs all the data. library size doubles if necessary
void VideoGameLibrary::addVideogameToArray() {

    const int MAX_LEN = 50;
    char titleStr[MAX_LEN];
    char platformStr[MAX_LEN];
    char genreStr[MAX_LEN];
    char ageRatingStr[MAX_LEN];
    int year;
    int igdb = 0;
    
    cin.ignore();
    cout << "\nVideo Game TITLE: ";
    cin.getline(titleStr, sizeof(titleStr));

    Text * title = new Text(titleStr);

    cout << "\n\nVideo Game PLATFORM: ";
    cin.getline(platformStr, sizeof(platformStr));

    Text * platform = new Text(platformStr);

    cout << "\n\nVideo Game YEAR: ";
    cin >> year;
    cin.ignore();

    cout << "\n\nVideo Game GENRE: ";
    cin.getline(genreStr, sizeof(genreStr));

    Text * genre = new Text(genreStr);

    cout << "\n\nVideo Game AGE RATING: ";
    cin.getline(ageRatingStr, sizeof(ageRatingStr));

    Text * ageRating = new Text(ageRatingStr);

    cout << "\n\nVideo Game USER RATING (out of 100): ";;
    cin >> igdb;

    while(igdb < 0 || igdb > 100) {
        cout << "pick between 0 and 100 for the igdb rating." << endl;
        cin >> igdb;
    }

    VideoGame * videoGame = new VideoGame(title, platform, year, genre, ageRating, igdb);

    if (numGames == maxGames) {
        resizeVideoGameArray();
    }
    
    videoGamesArray[numGames] = videoGame;

    numGames++;
}


//prints the videogames in the library with their corresponding data in an easy to read format
void VideoGameLibrary::displayVideoGames() {

    for(int i = 0; i < numGames; i++) {
        cout << "\n\n";
        cout << right << setw(50) << "----------Video Game  " << i+1 << "----------" << endl;
        videoGamesArray[i]->printVideoGameDetails();
        cout << endl;
    }
}

//prints the video game titles in the library. called in removeVideoGameFromArray
void VideoGameLibrary::displayVideoGameTitles() {
    for(int i = 0; i < numGames; i++) {
        cout << "Video Game " << i+1 << ": ";
        videoGamesArray[i]->getVideoGameTitle()->displayText();
        cout << "\n";
    }
}


//loads videogame data from text files and adds all of it to the library. library size doubles if necessary
void VideoGameLibrary::loadVideoGamesFromFile(const char * fileName) {
    ifstream inFile;

    inFile.open(fileName);

    if(!inFile.is_open()) {
        cout << "Sorry, I was unable to open the file." << endl;
        return;
    }

    const int SIZE = 10000;
    char temp[SIZE]; 
    int year;
    int userRating;

    while(inFile.getline(temp,SIZE)) {
        Text * title = new Text(temp);

        inFile.getline(temp, SIZE);
        Text * platform = new Text(temp);
        
        inFile >> year;
        inFile.ignore();

        inFile.getline(temp, SIZE);
        Text * genre = new Text(temp);

        inFile.getline(temp, SIZE);
        Text * ageRating = new Text(temp);

        inFile >> userRating;
        inFile.ignore();

        VideoGame * videoGame = new VideoGame(title, platform, year, genre, ageRating, userRating);

        if(numGames == maxGames) {
            resizeVideoGameArray();
        }

        videoGamesArray[numGames] = videoGame;

        numGames++;


        cout << title->getText() << " was added to the video game library!" << endl;
    }

    inFile.close();

    cout << numGames << " video games were read from the file and added to the library." << endl;
}

//removes videogames from the array chosen by the user
void VideoGameLibrary::removeVideoGameFromArray() {

    if(numGames < 1) {
        cout << "There must always be one video game in the library." << endl;
        return;
    }

    int userNum;

    cout << "\nChoose from the following video games to remove:" << endl << endl;

    displayVideoGameTitles();

    cout << "\nChoose a video game between 1 & " << numGames << ":  ";
    cin >> userNum;
    
    while(userNum < 1 || userNum > numGames) {
        cout << "You need to pick between 1 & " << numGames << ":  ";
        cin >> userNum;
    }

    userNum-= 1;

    cout << "\nThe video game \"";
    videoGamesArray[userNum]->getVideoGameTitle()->displayText();
    cout << "\" has been successfully deleted!" << endl;

    delete videoGamesArray[userNum];

    for(int i = userNum; i < numGames - 1; i++) {
        videoGamesArray[i] = videoGamesArray[i+1];
    }

    numGames--;

}

//saves the videogame library to a file named by the user
void VideoGameLibrary::saveToFile(string fileName) {
    ofstream outFile;

    outFile.open(fileName);

    if (!outFile.is_open()) {
        cout << "error opening file!" << endl;
        return;
    }

    for(int i = 0; i < numGames; i++) {
        videoGamesArray[i]->printVideoGameDetailsToFile(outFile);
    }

    outFile.close();

    cout << "All video games have been printed to the file!" << endl;
}