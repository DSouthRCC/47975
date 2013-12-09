//functional includes
#include <iostream>
#include <fstream>

//class includes
#include "Player.h"
#include "HowToPlay.h"

using namespace std;

//no global constants

//function prototypes
void header();
void mainMenu();
void playGame();
void about();
void howToPlay();
Player mkStats();

//begin program

int main() {
    //welcome and menu
    header();
    cout << endl << "Welcome to Ave Imperator!";
    cout << endl << endl << "Press Enter to continue.";
    cin.ignore();
    cout << endl;
    mainMenu();
    
    //class definitions
    Gladiator player(100, 20, 10, 10, 10, 10);
    Gladiator opp1(100, 20, 10, 10, 10, 10);

    //run combat loop
    //get opponent
    //display resolution

    //victory or death

    //exit program
    return 0;
}

void header() {
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
    short main;
    cout << endl << "Main Menu\n"
            << "----------------------\n"
            << "1: Play Ave Imperator\n"
            << "2: About Ave Imperator\n"
            << "3: How To Play\n"
            << "4: Exit Ave Imperator\n"
            << "----------------------";
    cout << endl << "Menu Selection: ";
    cin >> main;
    //check for out of bounds
    while (main < 1 || main > 4)
    {
        cout << endl << "You have entered and invalid menu choice, please re-enter";
    }
    if (main == 1)
    {
        playGame();
    }
    else if (main == 2)
    {
        about();
    }
    else if (main == 3)
    {
        howToPlay();
    }             
} 

void playGame() {
    Player stats;
    //get user choices
    stats = mkStats();
    //display user choices
    stats.prntPlyrStrgs();
}

void about() {
    cout << endl;
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
    mainMenu();
}

void howToPlay() {
    short menu;
    HowToPlay read; //read in to structure
    const short NUM_FILES = 4;
    fstream play; //stream reader
    cout << endl << "opening file to read" << endl;
    // Open a file for input in binary mode.
    play.open("howtoplay.dat", ios::in | ios::binary);
	// Test for errors.
	if (!play)
	{
		cout << "Error opening file. Program aborting.\n";
	}

	cout << "Here are the weapons in the file: \n\n";
	// Read the first record from the file.
	play.read(reinterpret_cast<char *>(&read),
			    sizeof(read));

	// While not at the end of the file,
	// display the records.
	while (!play.eof())
	{
		// Display the record.
		cout << read.gamePlay << endl;
		// Wait for the user to press the Enter key.
		cout << "\nPress the Enter key to see the next record.\n";
		cin.get();

		// Read the next record from the file.
		play.read(reinterpret_cast<char *>(&read),
			        sizeof(read));
	} 

	// Close the file.
	cout << "That's all the data in the file!\n";
	play.close();
    //HowTo Menu
    cout << endl << "How To Menu\n"
            << "--------------------\n"
            << "1: Playing the Game\n"
            << "2: Gladiator Stats\n"
            << "3: Combat\n"
            << "4: Weapons and Armor\n"
            << "5: Return to Main Menu\n"
            << "--------------------";
    cout << endl << "How To: ";
    cin >> menu;
    //bounds check
    while (menu < 1 || menu > 5)
    {
        cout << endl <<  cout << endl << "You have entered and invalid menu choice, please re-enter";
    }
    if (menu == 1)
    {
        cout << read.gamePlay;
    }
    if (menu == 2)
    {
        cout << read.playerStats;
    }
    if (menu == 3)
    {
        cout << read.combat;
    }
    if (menu == 4)
    {
        cout << read.wpnsArmr;
    }
    if (menu == 5)
    {
        mainMenu();
    }
    howToPlay();
}

Player mkStats() {
    //getter vars
    short getPlyrWep;
    short getPlyrArmr;
    short getPlyrStnc;
    //presets
    short plyrHlth; //health adjustment
    short plyrStr; //strength adjustment
    short plyrFati; //fatigue adjustment
    short plyrAgi; //agility adjustment
    short plyrDef; //defense adjustment
    short plyrMvSp; //move speed adjustment
    //variables
    string name; //get player name
    string style;
    string weapon; //get player weapon
    string armor; //get player armor
    short wpDmg; //weapon damage
    short wpSpd; //weapon speed
    short wpRch; //weapon reach 
    short wpDef; //defense adjustment from weapon
    short wpAgi; //agility adjustment from weapon
    short arDef; //defense adjustment from armor
    short arAgi; //agility adjustment from armor
    //get player name
    cout << "What is your name, Gladiator! ";
    getline(cin, name);
    //get weapon
    cout << "What weapon do you fight with? " << endl;
    cout << "1: One-Handed Short Sword" << endl
            << "2: One-Handed Mace" << endl
            << "3: One-Handed Hammer" << endl
            << "4: One-Handed Flail" << endl
            << "5: Two-Handed Long Sword" << endl
            << "6: Two-Handed Hammer" << endl
            << "7: Two Handed Trident" << endl
            << "8: Two Short Swords";
    cin >> getPlyrWep;
    //type, damage, speed, reach, defence adj, agility adj
    if (getPlyrWep = 1) {
        weapon = "Short Sword";
        wpDmg = 5;
        wpSpd = 4;
        wpRch = 1;
        wpDef = 0;
        wpAgi = 0;
    } else if (getPlyrWep = 2) {
        weapon = "One-Handed Mace";
        wpDmg = 6;
        wpSpd = 3;
        wpRch = 1;
        wpDef = 0;
        wpAgi = 0;
    } else if (getPlyrWep = 3) {
        weapon = "One-Handed Hammer";
        wpDmg = 6;
        wpSpd = 2;
        wpRch = 1;
        wpDef = 0;
        wpAgi = 0;
    } else if (getPlyrWep = 4) {
        weapon = "One-Handed Flail";
        wpDmg = 7;
        wpSpd = 2;
        wpRch = 2;
        wpDef = 0;
        wpAgi = 0;
    } else if (getPlyrWep = 5) {
        weapon = "Two-Handed Long Sword";
        wpDmg = 8;
        wpSpd = 2;
        wpRch = 3;
        wpDef = 2;
        wpAgi = 2;
    } else if (getPlyrWep = 6) {
        weapon = "Two-Handed Hammer";
        wpDmg = 12;
        wpSpd = 2;
        wpRch = 3;
        wpDef = 2;
        wpAgi = 3;
    } else if (getPlyrWep = 7) {
        weapon = "Two Handed Trident";
        wpDmg = 10;
        wpSpd = 3;
        wpRch = 4;
        wpDef = 2;
        wpAgi = 1;
    } else if (getPlyrWep = 8) {
        weapon = "Two Short Swords";
        wpDmg = 5;
        wpSpd = 4;
        wpRch = 1;
        wpDef = 1;
        wpAgi = 1;
    }
    //player armor	
    cout << "What armor do you wear? " << endl;
    cout << "1: Half Leather" << endl
            << "2: Full Leather" << endl
            << "3: Half Ring" << endl
            << "4: Full Ring" << endl
            << "5: Half Bronze" << endl
            << "6: Full Bronze" << endl;
    cin >> getPlyrArmr;
    //type, defense adj, agility adj
    if (getPlyrArmr = 1) {
        armor = "Half Leather";
        arDef = 3;
        arAgi = 2;
    } else if (getPlyrArmr = 2) {
        armor = "Full Leather";
        arDef = 4;
        arAgi = 3;
    } else if (getPlyrArmr = 3) {
        armor = "Half Ring";
        arDef = 4;
        arAgi = 2;
    } else if (getPlyrArmr = 4) {
        armor = "Full Ring";
        arDef = 5;
        arAgi = 4;
    } else if (getPlyrArmr = 5) {
        armor = "Half Bronze";
        arDef = 5;
        arAgi = 3;
    } else if (getPlyrArmr = 6) {
        armor = "Full Bronze";
        arDef = 6;
        arAgi = 5;
    }
    //style menu
    cout << "What is your fighting style: " << endl;
    cout << endl << "1: Agile";
    cout << endl << "2: Tactful";
    cout << endl << "3: Brute Force";
    cout << endl << "4: Meat Shield";
    cout << endl << "Fighting Style: ";
    cin >> getPlyrStnc;
    //style, health, strength, fatigue, agility, defense, movement
    if (getPlyrStnc = 1) {
        style = "Agile";
        plyrHlth = 0;
        plyrStr = 10;
        plyrFati = 16;
        plyrAgi = 14;
        plyrDef = 10;
        plyrMvSp = 10;
    } else if (getPlyrStnc = 2) {
        style = "Tactful";
        plyrHlth = 0;
        plyrStr = 13;
        plyrFati = 12;
        plyrAgi = 13;
        plyrDef = 12;
        plyrMvSp = 10;
    } else if (getPlyrStnc = 3) {
        style = "Brute";
        plyrHlth = 10;
        plyrStr = 17;
        plyrFati = 11;
        plyrAgi = 12;
        plyrDef = 10;
        plyrMvSp = 10;
    } else if (getPlyrStnc = 4) {
        style = "Tank";
        plyrHlth = 20;
        plyrStr = 13;
        plyrFati = 10;
        plyrAgi = 10;
        plyrDef = 17;
        plyrMvSp = 10;
    }
    //fill classes
    Player stats(name, style, weapon, wpDmg, wpSpd, wpRch, wpDef, wpAgi, armor, arDef, arAgi);
    stats.setAttributes(plyrHlth, plyrStr, plyrFati, plyrAgi, plyrDef, plyrMvSp);
    stats.setPlyrAtkP(plyrStr, wpDmg, wpSpd);
    //return
    return stats;
}