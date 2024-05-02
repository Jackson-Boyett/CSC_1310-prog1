/*
    name: Jackson Boyett
    title: Program 1
    date: 1/28/23
    purpose: keeps track of your library of video games
*/

#include "VideoGameLibrary.h"
#include <iomanip>
#include <fstream>

using namespace std;

int main() {

    int userChoice;
    int arrSize;
    int SIZE = 50;
    char filename[SIZE];
    string saveFileName;
    VideoGameLibrary * videoGameLibrary;
    ofstream outFile;
    

    cout << "\n\n" << "How many video games can your library hold?" << endl;
    cin >> arrSize;
    
    //allocates new video game library with its constructor based size given by user
    videoGameLibrary = new VideoGameLibrary(arrSize);

    // main menu looped until user wants to end and delete video game library
    do{
        userChoice = 0;

        cout << "\n\nWhat would you like to do?" << endl;
        cout << "1.  Load video games from file." << endl;
        cout << "2.  Save video games to a file." << endl;
        cout << "3.  Add a video game." << endl;
        cout << "4.  Remove a video game." << endl;
        cout << "5.  Display all video games." << endl;
        cout << "6.  Remove ALL video games from this library and end program." << endl;

        cout << "CHOOSE 1-6: ";
        cin >> userChoice;

        while(userChoice < 1 || userChoice > 6) {
            cout << "That is not a valid choice." << endl;
            cout << "CHOOSE 1-6: ";
            cin >> userChoice;
        }

        //branching for descisions on user input

        if(userChoice == 1) { //loads games from a file if user choses 1
            cout << "\nWhat is the name of the file you want to open?(example.txt): ";
            cin.ignore();
            cin.getline(filename, SIZE);

            videoGameLibrary->loadVideoGamesFromFile(filename);

        }
        else if(userChoice == 2) { //saves the library created by the user to a text file if user choses 2
            cout << "\nWhat do you want to name the file? (example.txt):  ";
            cin.ignore();
            getline(cin, saveFileName);

            videoGameLibrary->saveToFile(saveFileName);
        }
        else if(userChoice == 3) { // adds video game to the library and allows user to manually input the data if user choses 3
            videoGameLibrary->addVideogameToArray();
        }
        else if(userChoice == 4) { // removes video game from the library chosen by the user if user choses 4
            videoGameLibrary->removeVideoGameFromArray();
        }
        else if(userChoice == 5) { // displays all video games in library if user choses 5
           videoGameLibrary->displayVideoGames();
        }


    }while(userChoice != 6);

    delete videoGameLibrary;


    cout << "\nGOODBYE!";
    return 0;
}