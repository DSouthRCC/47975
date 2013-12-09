/* 
 * File:   Combat.h
 * Author: D
 *
 * Created on November 27, 2013, 8:32 PM
 * 
 * This program was created for CSC17A at
 * Riverside City College. It is not intended
 * for commercial use or distribution.
 *
 * Program structure derived from previous
 * projects. 
 */

//functional includes
#include <iostream>
#include <fstream>
#include <cstdlib>

//class includes
#include "Player.h"
#include "HowToPlay.h"
#include "Combat.h"

using namespace std;

//no global constants

//function prototypes
void header();
void mainMenu();
void playGame();
void about();
void howToPlay();
Player mkStats();
int getWepChoice();
int *getWeaponStats(int);
int getArmrChoice();
int *getArmrStats(int);
int getStyleChoice();
int *getStyleStats(int);
int *getOpp(int);
string getOppName(int);
char combat(string, int*, string, int *, int);
int getCpuAction();
int *getCmbtActs(int, int);
int getAttack(int &, int &);
int getDamage(int &, int &);
int getDodge(int &, int &);
int getParry(int &, int &);
void getOppHealth(string, int &);


//begin program

int main() {
    //set precision to 2 decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //welcome and menu
    header();
    cout << endl << "Welcome to Ave Imperator!";
    cout << endl << endl << "Press Enter to continue.";
    cin.ignore();
    cout << endl;
    mainMenu();
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
    int main;
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
    while (main < 1 || main > 4) {
        cout << endl << "You have entered and invalid menu choice, please re-enter";
    }
    if (main == 1) {
        playGame();
    } else if (main == 2) {
        about();
    } else if (main == 3) {
        howToPlay();
    }
}

void playGame() {
    char play; //char to continue playing or exit combat
    char begin; //check to enter combat
    int round = 1; //sets combat round
    int MAXROUNDS = 5; //total number of rounds
    string name;
    int statsSize = 6;
    int *plyrStats = new int[statsSize];
    Player stats;
    //get user choices
    stats = mkStats();
    //display user selected stats
    stats.prntPlyrStrgs();
    stats.prntPlyrStats();
    //prompt to begin combat
    cout << endl;
    cout << "Would you like to enter the Colosseum with this Gladiator?(y or n)";
    cin >> begin;
    if (begin == 'y') {
        for (int i = 0; i < MAXROUNDS; i++) {
            int *opponent;
            string oppName;
            opponent = getOpp(round);
            oppName = getOppName(round);
            //set user combat stats
            name = stats.getPlryName();
            plyrStats[0] = stats.getHealth();
            plyrStats[1] = stats.getPlryAtkP();
            plyrStats[2] = stats.getPlryAtkSp();
            plyrStats[3] = stats.getPlryBlk();
            plyrStats[4] = stats.getPlryDdge();
            plyrStats[5] = stats.getPlryPrry();
            //run combat
            play = combat(name, plyrStats, oppName, opponent, round);
            //combat prompts for continue and returns value
            if (play == 'y') {
                round++;
            } else if (play == 'n') {
                cout << endl << "Thank you for playing Ave Imperator!";
                cout << endl;
                exit(1);
            }
        }
    } else {
        playGame();
    }
    cin.ignore();
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
    int menu;
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
    while (menu < 1 || menu > 5) {
        cout << endl << cout << endl << "You have entered and invalid menu choice, please re-enter";
    }
    if (menu == 1) {
        cout << endl;
        string title; //shows title mainMenu
        fstream titleFile; //gets tile mainMenu
        // Open the file in input mode.
        titleFile.open("gamePlay.txt", ios::in);
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
    if (menu == 2) {
        cout << endl;
        string title; //shows title mainMenu
        fstream titleFile; //gets tile mainMenu
        // Open the file in input mode.
        titleFile.open("playerStats.txt", ios::in);
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
    if (menu == 3) {
        cout << endl;
        string title; //shows title mainMenu
        fstream titleFile; //gets tile mainMenu
        // Open the file in input mode.
        titleFile.open("combat.txt", ios::in);
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
    if (menu == 4) {
        cout << endl;
        string title; //shows title mainMenu
        fstream titleFile; //gets tile mainMenu
        // Open the file in input mode.
        titleFile.open("wepArmr.txt", ios::in);
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
    if (menu == 5) {
        mainMenu();
    }
    howToPlay();
}

Player mkStats() {
    //getter vars
    int getPlyrWep;
    int *wepStats;
    int getPlyrArmr;
    int *armrStats;
    int getPlyrStyl;
    int *styleStats;
    //variables
    string name; //get player name
    string style;
    string weapon; //get player weapon
    string armor; //get player armor
    //adjustments
    int plyrHlth; //adjusted health
    int plyrFati; //adjusted fatigue
    int plyrStr; //adjusted strength
    int plyrAgi; //adjusted agility
    int plyrDef; //adjusted defense
    int plyrMvSp; //adjusted movement
    //get player name
    cout << "What is your name, Gladiator! ";
    cin >> name;
    cin.ignore();
    cout << endl;
    //get weapon
    getPlyrWep = getWepChoice();
    wepStats = getWeaponStats(getPlyrWep);
    if (getPlyrWep == 1) {
        weapon = "Short Sword";
    } else if (getPlyrWep == 2) {
        weapon = "One-Handed Mace";
    } else if (getPlyrWep == 3) {
        weapon = "One-Handed Hammer";
    } else if (getPlyrWep == 4) {
        weapon = "One-Handed Flail";
    } else if (getPlyrWep == 5) {
        weapon = "Two-Handed Long Sword";
    } else if (getPlyrWep == 6) {
        weapon = "Two-Handed Hammer";
    } else if (getPlyrWep == 7) {
        weapon = "Two Handed Trident";
    } else if (getPlyrWep == 8) {
        weapon = "Two Short Swords";
    }
    cout << endl;
    //get armor
    getPlyrArmr = getArmrChoice();
    armrStats = getArmrStats(getPlyrArmr);
    if (getPlyrArmr == 1) {
        armor = "Half Leather";
    } else if (getPlyrArmr == 2) {
        armor = "Full Leather";
    } else if (getPlyrArmr == 3) {
        armor = "Half Ring";
    } else if (getPlyrArmr == 4) {
        armor = "Full Ring";
    } else if (getPlyrArmr == 5) {
        armor = "Half Bronze";
    } else if (getPlyrArmr == 6) {
        armor = "Full Bronze";
    }
    cout << endl;
    //style menu
    getPlyrStyl = getStyleChoice();
    styleStats = getStyleStats(getPlyrStyl);
    //style, health, strength, fatigue, agility, defense, movement
    if (getPlyrStyl == 1) {
        style = "Agile";
    } else if (getPlyrStyl == 2) {
        style = "Tactful";
    } else if (getPlyrStyl == 3) {
        style = "Brute";
    } else if (getPlyrStyl == 4) {
        style = "Tank";
    }
    //fill adjusted stats
    //wepStats0 = damage, wepStats1 = speed, wepStats2 = reach, wepStats3 = defAdj, wepStats4 = adjAdj, wepStats5 = fatiAdj
    //armrStats0 = defAdj, armrStats1 = adjAdj, armrStats2 = fatAdj, armrStats3 = moveAdj
    //styleStats[0] = health,
    Player stats(name, style, weapon, wepStats[0], wepStats[1], wepStats[2], wepStats[3], wepStats[4], wepStats[5], armor, armrStats[0], armrStats[1], armrStats[2], armrStats[3]);
    plyrHlth = stats.adjHealth(styleStats[0]);
    plyrFati = stats.adjFatigue(styleStats[1], wepStats[5], armrStats[2]);
    plyrStr = stats.adjStrength(styleStats[2]);
    plyrAgi = stats.adjAgility(styleStats[3], wepStats[4], armrStats[1]);
    plyrDef = stats.adjDefense(styleStats[4], wepStats[3], armrStats[0]);
    plyrMvSp = stats.adjMovement(styleStats[5], armrStats[3]);
    stats.setAttributes(plyrHlth, plyrFati, plyrStr, plyrAgi, plyrDef, plyrMvSp);
    stats.setPlyrAtkP(wepStats[0], wepStats[1]);
    stats.setPlyrAtkSp(wepStats[1]);
    stats.setPlyrBlk(wepStats[3], armrStats[0]);
    stats.setPlyrDdge();
    stats.setPlyrPrry();
    //return
    return stats;
}

int getWepChoice() {
    int plyrWep; //holds weapon choice
    cout << "What weapon do you fight with? " << endl;
    cout << "1: One-Handed Short Sword\n"
            << "2: One-Handed Mace\n"
            << "3: One-Handed Hammer\n"
            << "4: One-Handed Flail\n"
            << "5: Two-Handed Long Sword\n"
            << "6: Two-Handed Hammer\n"
            << "7: Two Handed Trident\n"
            << "8: Two Short Swords\n"
            << "Weapon Choice: ";
    cin >> plyrWep;
    //return weapon
    return plyrWep;
}

int *getWeaponStats(int choice) {
    int size = 6;
    int *wepStats = new int[size];
    int wpDmg; //weapon damage
    int wpSpd; //weapon speed
    int wpRch; //weapon reach 
    int wpDef; //defense adjustment from weapon
    int wpAgi; //agility adjustment from weapon
    int wpFti; //fatigue adjustment from weapon
    //type, damage, speed, reach, defense adj, agility adj
    if (choice == 1) {
        wpDmg = 5;
        wpSpd = 4;
        wpRch = 1;
        wpDef = 0;
        wpAgi = 0;
        wpFti = 0;
    } else if (choice == 2) {
        wpDmg = 6;
        wpSpd = 3;
        wpRch = 1;
        wpDef = 0;
        wpAgi = 0;
        wpFti = 0;
    } else if (choice == 3) {
        wpDmg = 6;
        wpSpd = 2;
        wpRch = 1;
        wpDef = 0;
        wpAgi = 0;
        wpFti = 0;
    } else if (choice == 4) {
        wpDmg = 7;
        wpSpd = 2;
        wpRch = 2;
        wpDef = 0;
        wpAgi = 0;
        wpFti = 1;
    } else if (choice == 5) {
        wpDmg = 8;
        wpSpd = 2;
        wpRch = 3;
        wpDef = 2;
        wpAgi = 2;
        wpFti = 1;
    } else if (choice == 6) {
        wpDmg = 12;
        wpSpd = 2;
        wpRch = 3;
        wpDef = 2;
        wpAgi = 3;
        wpFti = 2;
    } else if (choice == 7) {
        wpDmg = 10;
        wpSpd = 3;
        wpRch = 4;
        wpDef = 2;
        wpAgi = 1;
        wpFti = 1;
    } else if (choice == 8) {
        wpDmg = 5;
        wpSpd = 4;
        wpRch = 1;
        wpDef = 1;
        wpAgi = 1;
        wpFti = 2;
    }
    //set values
    wepStats[0] = wpDmg;
    wepStats[1] = wpSpd;
    wepStats[2] = wpRch;
    wepStats[3] = wpDef;
    wepStats[4] = wpAgi;
    wepStats[5] = wpFti;
    //return
    return wepStats;
}

int getArmrChoice() {
    int plyrArmr;
    cout << "What armor do you wear? " << endl;
    cout << "1: Half Leather\n"
            << "2: Full Leather\n"
            << "3: Half Ring\n"
            << "4: Full Ring\n"
            << "5: Half Bronze\n"
            << "6: Full Bronze\n"
            << "Armor Choice: ";
    cin >> plyrArmr;
    //return armor choice
    return plyrArmr;
}

int *getArmrStats(int choice) {
    int size = 4;
    int *armrStats = new int[size];
    int arDef; //defense adjustment from armor
    int arAgi; //agility adjustment from armor
    int arFti; //fatigue adjustment from armor
    int arMv; //movement adjustment from armor
    //type, defense adj, agility adj
    if (choice == 1) {
        arDef = 3;
        arAgi = 2;
        arFti = 0;
        arMv = 0;
    } else if (choice == 2) {
        arDef = 4;
        arAgi = 3;
        arFti = 0;
        arMv = 1;
    } else if (choice == 3) {
        arDef = 4;
        arAgi = 2;
        arFti = 0;
        arMv = 0;
    } else if (choice == 4) {
        arDef = 5;
        arAgi = 4;
        arFti = 1;
        arMv = 1;
    } else if (choice == 5) {
        arDef = 5;
        arAgi = 3;
        arFti = 1;
        arMv = 2;
    } else if (choice == 6) {
        arDef = 6;
        arAgi = 5;
        arFti = 1;
        arMv = 2;
    }
    //set values
    armrStats[0] = arDef;
    armrStats[1] = arAgi;
    armrStats[2] = arFti;
    armrStats[3] = arMv;
    //return
    return armrStats;
}

int getStyleChoice() {
    int style;
    cout << "What is your fighting style: " << endl;
    cout << "1: Agile\n"
            << "2: Tactful\n"
            << "3: Brute Force\n"
            << "4: Meat Shield\n"
            << "Fighting Style: ";
    cin >> style;
    //return style
    return style;
}

int *getStyleStats(int choice) {
    int size = 6;
    int *styleStats = new int[size];
    int hlthAdj; //value to adjust base health
    int fatiAdj; //value to adjust base fatigue
    int strAdj; //value to adjust base strength
    int agiAdj; //value to adjust base agility
    int defAdj; //value to adjust base defense
    int moveAdj; //value to adjust base movement
    //style, health, strength, fatigue, agility, defense, movement
    if (choice == 1) {
        hlthAdj = 0;
        fatiAdj = 16;
        strAdj = 10;
        agiAdj = 14;
        defAdj = 10;
        moveAdj = 10;
    } else if (choice == 2) {
        hlthAdj = 0;
        fatiAdj = 12;
        strAdj = 10;
        agiAdj = 13;
        defAdj = 12;
        moveAdj = 10;
    } else if (choice == 3) {
        hlthAdj = 10;
        fatiAdj = 11;
        strAdj = 10;
        agiAdj = 12;
        defAdj = 10;
        moveAdj = 10;
    } else if (choice == 4) {
        hlthAdj = 20;
        fatiAdj = 10;
        strAdj = 10;
        agiAdj = 10;
        defAdj = 17;
        moveAdj = 10;
    }
    //set values
    styleStats[0] = hlthAdj;
    styleStats[1] = fatiAdj;
    styleStats[2] = strAdj;
    styleStats[3] = agiAdj;
    styleStats[4] = defAdj;
    styleStats[5] = moveAdj;
    //return
    return styleStats;
}

int *getOpp(int round) {
    int size = 5;
    int *opponent = new int[size];
    string oppName;
    //opponent[0] = health, opponent[1] = attack power, opponent[2] = attack speed opponent[3] = block rating, opponent[4] = dodge rating, opponent[5] = parry rating
    if (round == 1) {
        opponent[0] = 90;
        opponent[1] = 35;
        opponent[2] = 35;
        opponent[3] = 20;
        opponent[4] = 20;
        opponent[5] = 20;
    } else if (round == 2) {
        opponent[0] = 100;
        opponent[1] = 40;
        opponent[2] = 35;
        opponent[3] = 25;
        opponent[4] = 20;
        opponent[5] = 25;
    } else if (round == 3) {
        opponent[0] = 110;
        opponent[1] = 65;
        opponent[2] = 30;
        opponent[3] = 30;
        opponent[4] = 17;
        opponent[5] = 20;
    } else if (round == 4) {
        opponent[0] = 120;
        opponent[1] = 45;
        opponent[2] = 33;
        opponent[3] = 31;
        opponent[4] = 17;
        opponent[5] = 20;
    } else if (round == 5) {
        opponent[0] = 120;
        opponent[1] = 60;
        opponent[2] = 40;
        opponent[3] = 40;
        opponent[4] = 35;
        opponent[5] = 25;
    }
    //return opponent
    return opponent;
}

string getOppName(int round) {
    string name;
    if (round == 1) {
        name = "Cassius";
    } else if (round == 2) {
        name = "Markus";
    } else if (round == 3) {
        name = "Brutus Titus";
    } else if (round == 4) {
        name = "Oram the Slave";
    } else if (round == 5) {
        name = "Alexander Aurellis Antonius";
    }
    //return
    return name;
}

char combat(string plyrName, int *plyrStats, string oppName, int *oppStats, int round) {
    char advance;
    char wounded;
    int cmbtAct;
    int cpuCombat;
    cout << endl << "Welcome to the Tournament of the Emperor!" << endl;
    cout << endl << "On this, Day " << round << " we will see our challenger " << plyrName <<
            " battle " << oppName << "!\n";
    cout << endl << "Ave Imperator, Morituri te Salutant!\n<Hail Emperor, Those who are about to die, Salute you!>" << endl;
    //[0] = health, [1] = attack power, [2] = attack speed, [3] = block rating, [4] = dodge rating, [5] = parry rating
    cin.ignore();
    //combat loop
    while (oppStats[0] >= 5) {
        //reset all variables at the beginning of combat rounds
        int plyrAtk = 0;
        int plyrDmg = 0;
        int plyrBlk = 0;
        int plyrDdge = 0;
        int plyrPrry = 0;
        int oppAtk = 0;
        int oppDmg = 0;
        int oppBlk = 0;
        int oppDdge = 0;
        int oppPrry = 0;
        //get cpu action
        cpuCombat = getCpuAction();
        //player combat menu
        cout << endl << "Chose your action\n"
                << "1: Attack\n"
                << "2: Block\n"
                << "3: Dodge\n"
                << "4: Parry\n"
                << "Combat Action: ";
        cin >> cmbtAct;
        //both attack
        if (cpuCombat == 1 && cmbtAct == 1) {
            cout << endl;
            //opponent attack
            cout << oppName << " attacks! ";
            oppAtk = getAttack(oppStats[2], plyrStats[3]);
            oppDmg = getDamage(oppStats[1], oppAtk);
            cout << "striking for " << oppDmg << " undefended damage" << endl;
            //player attack
            cout << "You attack! ";
            plyrAtk = getAttack(plyrStats[2], oppStats[3]);
            plyrDmg = getDamage(plyrStats[1], plyrAtk);
            cout << "dealing " << plyrDmg << " undefended damage" << endl;
            //damage
            plyrStats[0] = plyrStats[0] - oppDmg;
            oppStats[0] = oppStats[0] - plyrDmg;
            cout << endl << "You can take " << plyrStats[0] << " more damage";
            getOppHealth(oppName, oppStats[0]);
        }
        //both block
        if (cpuCombat == 2 && cmbtAct == 2) {
            //no combat result
            cout << endl;
            cout << oppName << " takes a defensive position";
            cout << endl;
            cout << "You prepare for an incoming attack";
        }
        //both dodge
        if (cpuCombat == 3 && cmbtAct == 3) {
            //no combat result
            cout << endl;
            cout << oppName << " slides away from you";
            cout << endl;
            cout << "You slide away from an attack";
        }
        //both parry
        if (cpuCombat == 4 && cmbtAct == 4) {
            //no combat result
            cout << endl;
            cout << oppName << " looks for an incoming attack";
            cout << endl;
            cout << "You are anticipating an incoming attack";
        }
        //opponent attack - player block
        if (cpuCombat == 1 && cmbtAct == 2) {
            cout << endl;
            //opponent attack
            cout << oppName << " attacks! ";
            oppAtk = getAttack(oppStats[2], plyrStats[3]);
            oppDmg = getDamage(oppStats[1], oppAtk);
            cout << " swinging for " << oppDmg << endl;
            //player blocks
            cout << "You take a defensive stance ";
            plyrBlk = plyrStats[3];
            oppDmg = oppDmg - plyrBlk;
            if (oppDmg < 0) {
                cout << endl << "blocking all of the damage";
                oppDmg = 0;
            } else {
                cout << " but take " << oppDmg << " damage";
            }
            //damage
            plyrStats[0] = plyrStats[0] - oppDmg;
            cout << "You can take " << plyrStats[0] << " more damage";
        }
        //opponent attack - player dodge
        if (cpuCombat == 1 && cmbtAct == 3) {
            cout << endl;
            //opponent attack
            cout << oppName << " attacks! ";
            oppAtk = getAttack(oppStats[2], plyrStats[3]);
            oppDmg = getDamage(oppStats[1], oppAtk);
            cout << " striking for " << oppDmg << endl;
            //player dodge
            cout << "You move away ";
            plyrDdge = getDodge(plyrStats[4], oppAtk);
            oppDmg = oppDmg - plyrDdge;
            if (oppDmg < 0) {
                cout << endl << "dodging all of the damage";
                oppDmg = 0;
            } else {
                cout << " but still take " << oppDmg << " damage";
            }
            //damage
            plyrStats[0] = plyrStats[0] - oppDmg;
            cout << "You can take " << plyrStats[0] << " more damage";
        }
        //opponent attacks - player paries
        if (cpuCombat == 1 && cmbtAct == 4) {
            cout << endl;
            //opponent attack
            cout << oppName << " attacks! " << endl;
            oppAtk = getAttack(oppStats[2], plyrStats[3]);
            oppDmg = getDamage(oppStats[1], oppAtk);
            //player parry
            cout << "You move to parry" << endl;
            plyrPrry = getParry(plyrStats[5], oppAtk); //parry uses versus attack power
            if (plyrPrry > oppDmg) {
                cout << "deflecting the damage and returning ";
                plyrDmg = plyrStats[1]*.4;
                cout << plyrDmg;
            } else {
                cout << " deflecting the damage\nbut are unable to counter" << endl;
            }
            oppStats[0] = oppStats[0] - plyrDmg;
            getOppHealth(oppName, oppStats[0]);
        }
        //opponent blocks - player attacks
        if (cpuCombat == 2 && cmbtAct == 1) {
            cout << endl;
            //player attack
            cout << "You attack! ";
            plyrAtk = getAttack(plyrStats[2], oppStats[3]);
            plyrDmg = getDamage(plyrStats[1], plyrAtk);
            cout << " striking for " << plyrDmg << endl;
            //opponent blocks
            cout << oppName << " sets up defensively ";
            oppBlk = oppStats[3];
            plyrDmg = plyrDmg - oppBlk;
            if (plyrDmg < 0) {
                cout << endl << "blocking all of the damage";
                plyrDmg = 0;
            } else {
                cout << "but still takes " << plyrDmg << " damage";
            }
            //damage
            oppStats[0] = oppStats[0] - plyrDmg;
            getOppHealth(oppName, oppStats[0]);
        }
        //opponent blocks - player dodges
        if (cpuCombat == 2 && cmbtAct == 3) {
            cout << endl;
            //non combat action
            cout << endl;
            cout << oppName << " takes a defensive position";
            cout << endl;
            cout << "You step back from your opponent";
        }
        //opponent blocks - player paries
        if (cpuCombat == 2 && cmbtAct == 4) {
            cout << endl;
            //non combat action
            cout << endl;
            cout << oppName << " takes a defensive position";
            cout << endl;
            cout << "You look to deflect an attack that never comes";
        }
        //opponent dodges - player attacks
        if (cpuCombat == 3 && cmbtAct == 1) {
            cout << endl;
            //player attack
            cout << "You attack! ";
            plyrAtk = getAttack(plyrStats[2], oppStats[3]);
            plyrDmg = getDamage(plyrStats[1], plyrAtk);
            cout << " lunging for " << plyrDmg << endl;
            //opponent dodge
            cout << oppName << " jumps away ";
            oppDdge = getDodge(oppStats[4], plyrAtk);
            plyrDmg = plyrDmg - oppDdge;
            if (plyrDmg < 0) {
                cout << endl << "dodging all of the damage";
                plyrDmg = 0;
            } else {
                cout << " and takes " << plyrDmg;
            }
            //damage
            oppStats[0] = oppStats[0] - plyrDmg;
            getOppHealth(oppName, oppStats[0]);
        }
        //opponent dodges - player blocks
        if (cpuCombat == 3 && cmbtAct == 2) {
            cout << endl;
            //non combat action
            cout << endl;
            cout << oppName << " slides away from you";
            cout << endl;
            cout << "You prepare to block an incoming attack";
        }
        //opponent dodges - player paries
        if (cpuCombat == 3 && cmbtAct == 4) {
            cout << endl;
            //non combat action
            cout << endl;
            cout << oppName << " jumps back, anticipating an attack";
            cout << endl;
            cout << "You look to parry an attack, but it never comes";
        }
        //opponent paries - player attacks
        if (cpuCombat == 4 && cmbtAct == 1) {
            cout << endl;
            //player attack
            cout << "You attack! ";
            plyrAtk = getAttack(plyrStats[2], oppStats[3]);
            plyrDmg = getDamage(plyrStats[1], plyrAtk);
            cout << " swinging for " << plyrDmg << endl;
            //opponent parry
            cout << oppName << " paries! ";
            oppPrry = getParry(oppStats[5], plyrAtk); //parry uses versus attack power
            if (oppPrry > plyrDmg) {
                cout << "deflecting the damage and returning ";
                oppDmg = oppStats[1]*.4;
                cout << oppDmg;
            } else {
                cout << " deflecting the damage\nbut is unable to counter" << endl;
            }
            plyrStats[0] = plyrStats[0] - oppDmg;
            cout << "You can take " << plyrStats[0] << " more damage";
        }
        //opponent paries - player blocks
        if (cpuCombat == 4 && cmbtAct == 2) {
            cout << endl;
            //non combat action
            cout << endl;
            cout << oppName << " anticipates an attack, but it never comes";
            cout << endl;
            cout << "You take up a defensive stance, preparing to block";
        }
        //opponent paries - player dodges
        if (cpuCombat == 4 && cmbtAct == 3) {
            cout << endl;
            //non combat action
            cout << endl;
            cout << oppName << " moves to deflect an attack";
            cout << endl;
            cout << "You slide away from " << oppName;
        }
        if (plyrStats[0] <= 5 && plyrStats[0] >= 0) {
            cout << "You are gravely wounded, will you yield to the emperor's will\n"
                    "or continue to fight?" << endl << "enter y to yield, n to continue";
            cin >> wounded;
            if (wounded == 'y') {
                cout << endl << "The emperor's favor shines on you today, he wills you to live.";
            }
        }
        if (plyrStats[0] < 0) {
            cout << endl << "You have been killed in combat" << endl;
            exit(2);
        }
    }
	//end of combat
    if (round <= 4) {
        cout << endl << "You are Victorious!";
        cout << endl << endl << "Advance to next day?(y or n)" << endl;
		cout << "\"y\" will advance to the next day, \"n\" will exit the program ";
        cin >> advance;
        while (advance != 'y' && advance != 'n') {
            cout << endl << "You have entered an invalid entry, please re-enter: ";
            cin >> advance;
        }
        return advance;
    } else if (round == 5)
	{
		cout << endl << "You have completed the emperor's tournament!\n"
		<< "You shall be rewarded with a position of honor in Rome!" << endl;
		}
	else {
        cout << endl << "Thank you for playing Ave Imperator!";
        cout << endl;
        exit(1);
    }
}

int getCpuAction() {
    int oppCh = 0; //cpu choice
    srand(static_cast<unsigned int> (time(0)));
    //set random 1 through 5 for cpu
    oppCh = rand() % 4 + 1;

    return oppCh;
}

int getAttack(int &attkSpd, int &defRate) {
    int attk = 0;
    attk = setAttack(attkSpd, defRate);
    //return
    return attk;
}

int getDamage(int &wepDmg, int &atkMod) {
    int dmg = 0;
    dmg = setDamage(wepDmg, atkMod);
    //return
    return dmg;
}

int getDodge(int &dodge, int &atkMod) {
    int dodged;
    dodged = setDodge(dodge, atkMod);
    //return
    return dodged;
}

int getParry(int &parRate, int &atkMod) {
    int parry;
    parry = setParry(parRate, atkMod);

    return parry;
}

void getOppHealth(string name, int &health) {
    //opponent health status
    if (health <= 70 && health > 40) {
        cout << endl << name << " is looking slightly weak" << endl;
    } else if (health <= 40 && health > 10) {
        cout << endl << name << " looks damaged" << endl;
    } else if (health <= 10 && health > 0) {
        cout << endl << name << " is staggered" << endl;
    } else if (health <= 0) {
        cout << endl << name << " has been defeated!" << endl;
    } else if (health > 70) {
        cout << endl << name << " is standing strong" << endl;
    }
}