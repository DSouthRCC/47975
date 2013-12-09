
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "Weapon.h"
#include "Opponent.h"

using namespace std;

void title();
void mainMenu();
void aboutGame();
void mkPlayer();
void wepsMenu();
void armrMenu();

int main(int argc, char** argv) {
    title();
    mainMenu();
    mkPlayer();

    return 0;
}

void title() {
    string title; //shows title mainMenu
    fstream titleFile; //gets tile mainMenu
    // Open the file in input mode.
    titleFile.open("title.txt", ios::in);
    // If the file was successfully opened, continue.
    if (titleFile) {
        // Read an item from the file.
        getline(titleFile, title);
        // read in file.
        while (titleFile) {
            // Display the last item read.
            cout << title << endl;
            // Read the next item.
            getline(titleFile, title);
        }
        // Close the file.
        titleFile.close();
    } else {
        cout << "ERROR: Cannot open file.\n";
    }
}

void mainMenu() {
    short mainMenu = 0; //used for main menu    
    //begin mainMenu loop
    do {
        //mainMenu options
        cout << "Welcome! Make a selection:\n";
        cout << endl
                << "1: About the Game\n"
                << "2: New Game\n"
                << "3: Exit\n"
                << endl
                << "Enter your choice and press Return: ";
        cin >> mainMenu;
        cout << endl;
        //process choices	
        switch (mainMenu) {
            case 1:
                //How To Play
                //*
                break;
            case 2:
                //Create New Player
                //*
                break;
            case 3:
                //exit message
                cout << endl << "Thanks for playing XX!\n" << endl;
                //closes program
                exit(1);
                break;
        }
        //provide output for incorrect choice
        if (mainMenu < 1 || mainMenu > 3) {
            cout << endl << "You have selected an invalid input.  Please select again:";
        }
    }//end mainMenu loop
    while (mainMenu != 3);
}

void about() {
    short aboutMenu = 0; //used for main menu    
    //begin mainMenu loop
    do {
        //mainMenu options
        cout << "Welcome! Make a selection:\n";
        cout << endl
                << "1: About the Game\n"
                << "2: Playing the Game\n"
                << "3: Player Stats\n"
                << "4: Combat\n"
                << "5: Weapons and Armor\n"
                << "6: Return to Main Menu\n"
                << endl
                << "Enter your choice and press Return: ";
        cin >> mainMenu;
        cout << endl;
        //process choices	
        switch (mainMenu) {
            case 1:
                //About the Game
                aboutGame();
                break;
            case 2:
                //Create New Player
                //*
                break;
            case 3:
                //Create New Player
                //*
                break;
            case 4:
                //Create New Player
                //*
                break;
            case 5:
                //Create New Player
                //*
                break;
            case 6:
                //Return to Main
                mainMenu();
                break;

        }
        //provide output for incorrect choice
        if (mainMenu < 1 || mainMenu > 6) {
            cout << endl << "You have selected an invalid input.  Please select again:";
        }
    }//end mainMenu loop
    while (mainMenu != 6);
}

void aboutGame()
{
    string title; //shows title mainMenu
    fstream titleFile; //gets tile mainMenu
    // Open the file in input mode.
    titleFile.open("about.txt", ios::in);
    // If the file was successfully opened, continue.
    if (titleFile) {
        // Read an item from the file.
        getline(titleFile, title);
        // read in file.
        while (titleFile) {
            // Display the last item read.
            cout << title << endl;
            // Read the next item.
            getline(titleFile, title);
        }
        // Close the file.
        titleFile.close();
    } else {
        cout << "ERROR: Cannot open file.\n";
    }    
}
void mkPlayer() {

    char player[25];
    short health;
    short agi;
    short str;
    short def;
    short fatigue;

    cout << "Enter your name Gladiator! ";
    cin.getline(player, 25);

    //create attributes

    cout << endl << "Here are your starting attributes: ";
    cout << endl << "Health: " << health;
    cout << endl << "Agility rating: " << agi;
    cout << endl << "Strength Rating: " << str;
    cout << endl << "Defensive Rating: " << def;
    cout << endl << "Fatigue Level: " << fatigue;

    cout << endl << "Choose your weapon type: ";
    wepsMenu();

    cout << endl << "Choose your armor type: ";
    armrMenu();
}

void wepsMenu() {
    //load weapons structure

    cout << endl;
    cout << "1: W1" << endl;
    cout << "2: W2" << endl;
    cout << "3: W3" << endl;
    cout << "4: W4" << endl;
    cout << "5: W5" << endl;
    cout << "6: W6" << endl;
    cout << "7: W7" << endl;
    cout << "8: W8" << endl;

    //load choice from structure
}

void armrMenu() {
    //load armor structure

    cout << endl;
    cout << "1: A1" << endl;
    cout << "2: A2" << endl;
    cout << "3: A3" << endl;
    cout << "4: A4" << endl;
    cout << "5: A5" << endl;
    cout << "6: A6" << endl;

    //load choice from structure

}