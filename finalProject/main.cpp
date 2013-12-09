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
int *getWeaponStats(short);
int getArmrChoice();
int *getArmrStats(short);
int getStyleChoice();
int *getStyleStats(short);
int *getOpp(int);
string getOppName(int);
char combat(string, int*, string, int *, int);
int getCpuAction();
int *getCmbtActs(int, int);


//begin program

int main() {
    //welcome and menu
    header();
    cout << endl << "Welcome to Ave Imperator!";
    cout << endl << endl << "Press Enter to continue.";
    cin.ignore();
    cout << endl;
    mainMenu();

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
    char begin;
    int round = 1; //sets combat round
    int MAXROUNDS = 5; //total number of rounds
    string name;
    int statsSize = 4;
    int *plyrStats = new int[statsSize];
    Player stats;
    //get user choices
    stats = mkStats();
    //display user choices
    stats.prntPlyrStrgs();
    stats.prntPlyrStats();
    name = stats.getPlryName();
    plyrStats[0] = stats.getHealth();
    plyrStats[1] = stats.getPlryAtkP();
    plyrStats[2] = stats.getPlryBlk();
    plyrStats[3] = stats.getPlryDdge();
    plyrStats[4] = stats.getPlryPrry();
    cout << endl;
    cout << "Would you like to enter the Colosseum with this Gladiator?(y or n)";
    cin >> begin;
    if (begin == 'y') {
        cout << endl << "Your combat stats are: "
                << "Health: " << plyrStats[0] << "\t"
                << "Attack Power: " << plyrStats[1] << "\t"
                << "Block Rating: " << plyrStats[2] << "\t"
                << "Dodge Rating: " << plyrStats[3] << "\t"
                << "Parry Rating: " << plyrStats[4] << endl;
    } else {
        mkStats();
    }
    cin.ignore();
    char play;

    for (int i = 0; i < MAXROUNDS; i++) {
        int *opponent;
        string oppName;
        opponent = getOpp(round);
        oppName = getOppName(round);
        play = combat(name, plyrStats, oppName, opponent, round);
        cout << endl << "your reply is: " << play << endl;
        if (play == 'y') {
            round++;
        }
        if (play == 'n') {
            cout << endl << "Thank you for playing Ave Imperator!";
            cout << endl;
            exit(1);
        }
    }
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
    //test for errors
    if (!play) {
        cout << "Error opening file. Program aborting.\n";
    }
    //read in first record
    play.read(reinterpret_cast<char *> (&read),
            sizeof (read));
    //loop for end of file
    while (!play.eof()) {
        //load all other records
        play.read(reinterpret_cast<char *> (&read),
                sizeof (read));
    }
    //close file.
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
    while (menu < 1 || menu > 5) {
        cout << endl << cout << endl << "You have entered and invalid menu choice, please re-enter";
    }
    if (menu == 1) {
        cout << read.gamePlay;
    }
    if (menu == 2) {
        cout << read.playerStats;
    }
    if (menu == 3) {
        cout << read.combat;
    }
    if (menu == 4) {
        cout << read.wpnsArmr;
    }
    if (menu == 5) {
        mainMenu();
    }
    howToPlay();
}

Player mkStats() {
    //getter vars
    short getPlyrWep;
    int *wepStats;
    short getPlyrArmr;
    int *armrStats;
    short getPlyrStyl;
    int *styleStats;
    //variables
    string name; //get player name
    string style;
    string weapon; //get player weapon
    string armor; //get player armor
    //adjustments
    short plyrHlth; //adjusted health
    short plyrFati; //adjusted fatigue
    short plyrStr; //adjusted strength
    short plyrAgi; //adjusted agility
    short plyrDef; //adjusted defense
    short plyrMvSp; //adjusted movement
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
    plyrFati = stats.adjFatigue(styleStats[1]);
    plyrStr = stats.adjStrength(styleStats[2]);
    plyrAgi = stats.adjAgility(styleStats[3]);
    plyrDef = stats.adjDefense(styleStats[4]);
    plyrMvSp = stats.adjMovement(styleStats[5]);
    stats.setAttributes(plyrHlth, plyrFati, plyrStr, plyrAgi, plyrDef, plyrMvSp);
    stats.setPlyrAtkP(wepStats[0], wepStats[1]);
    stats.setPlyrBlk();
    stats.setPlyrDdge(plyrMvSp);
    stats.setPlyrPrry(wepStats[3]);
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

int *getWeaponStats(short choice) {
    int size = 6;
    int *wepStats = new int[size];
    short wpDmg; //weapon damage
    short wpSpd; //weapon speed
    short wpRch; //weapon reach 
    short wpDef; //defense adjustment from weapon
    short wpAgi; //agility adjustment from weapon
    short wpFti; //fatigue adjustment from weapon
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

int *getArmrStats(short choice) {
    int size = 4;
    int *armrStats = new int[size];
    short arDef; //defense adjustment from armor
    short arAgi; //agility adjustment from armor
    short arFti; //fatigue adjustment from armor
    short arMv; //movement adjustment from armor
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

int *getStyleStats(short choice) {
    int size = 6;
    int *styleStats = new int[size];
    short hlthAdj; //value to adjust base health
    short fatiAdj; //value to adjust base fatigue
    short strAdj; //value to adjust base strength
    short agiAdj; //value to adjust base agility
    short defAdj; //value to adjust base defense
    short moveAdj; //value to adjust base movement
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
    //opponent[0] = health, opponent[1] = attack power, opponent[2] = block rating, opponent[3] = dodge rating, opponent[4] = parry rating
    if (round == 1) {
        opponent[0] = 100;
        opponent[1] = 35;
        opponent[2] = 30;
        opponent[3] = 30;
        opponent[4] = 30;
    } else if (round == 2) {
        opponent[0] = 100;
        opponent[1] = 30;
        opponent[2] = 30;
        opponent[3] = 30;
        opponent[4] = 30;
    } else if (round == 3) {
        opponent[0] = 100;
        opponent[1] = 30;
        opponent[2] = 30;
        opponent[3] = 30;
        opponent[4] = 30;
    } else if (round == 4) {
        opponent[0] = 100;
        opponent[1] = 30;
        opponent[2] = 30;
        opponent[3] = 30;
        opponent[4] = 30;
    } else if (round == 5) {
        opponent[0] = 100;
        opponent[1] = 30;
        opponent[2] = 30;
        opponent[3] = 30;
        opponent[4] = 30;
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
    int plyrHealth = plyrStats[0];
    int oppHealth = oppStats[0];
    cout << endl << "Welcome to the Tournament of the Emperor!" << endl;
    cout << endl << "On Day " << round << " we will see our challenger " << plyrName <<
            " battle " << oppName << "!";
    cout << endl << "Ave Imperator!" << endl;
    //[0] = health, [1] = attack power, [2] = block rating, [3] = dodge rating, [4] = parry rating

    cout << endl << "Player Stats: " << endl
            << "Health: " << plyrHealth << "\t"
            << "Attack Power: " << plyrStats[1] << "\t"
            << "Block Rating: " << plyrStats[2] << "\t"
            << "Dodge Rating: " << plyrStats[3] << "\t"
            << "Parry Rating: " << plyrStats[4] << endl;
    cout << endl;
    cout << endl << "Opponent Stats: " << endl
            << "Health: " << oppHealth << "\t"
            << "Attack Power: " << oppStats[1] << "\t"
            << "Block Rating: " << oppStats[2] << "\t"
            << "Dodge Rating: " << oppStats[3] << "\t"
            << "Parry Rating: " << oppStats[4] << endl;
    cout << endl << "Press enter to continue";
    cin.ignore();
    //combat loop
     while (oppHealth >= 5) {
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
        cout << endl << "Choose your combat action\n"
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
            cout << oppName << " attacks ";
            oppAtk = attack(oppStats[1], plyrStats[2]);     
            if (oppAtk <= 0) {
                cout << "but misses";
                oppDmg = 0;
            } else if (oppAtk >= 1) {
                cout << oppName << " strikes for ";
                oppDmg = getDamage(oppStats[1], plyrStats[2], oppAtk);
                cout << oppDmg << " undefended damage";
            }
            //player attack
            plyrAtk = attack(plyrStats[1], oppStats[2]);
            if (plyrAtk <= 0) {
                cout << "You attack, but miss";
                plyrDmg = 0;
            } else if (plyrAtk >= 1) {
                plyrDmg = getDamage(plyrStats[1], oppStats[2], plyrAtk);
                cout << "You attack, striking for " << plyrDmg << " undefended damage";
            }
            //post damage
           plyrHealth =plyrHealth - oppDmg;
            oppHealth = oppHealth - plyrDmg;
            //show current health
            cout << endl << "Player Health: " << plyrHealth;
            cout << endl << "Opp Health: " << oppHealth;
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
            cout << oppName << " attacks " << endl;
            oppAtk = attack(oppStats[1], plyrStats[2]);
            if (oppAtk = 0) {
                cout << "but misses";
                oppDmg = 0;
            } else if (oppAtk >= 1) {
                cout << oppName << " strikes for ";
                oppDmg = getDamage(oppStats[1], plyrStats[2], oppAtk);
                cout << oppDmg << " undefended damage";
            }
            //player block versus attack
            plyrBlk = getBlock(oppDmg, plyrStats[2]);
            cout << "You blocked ";
            if (plyrBlk > oppDmg) {
                cout << "all ";
                oppDmg = 0;
            } else {
                cout << plyrBlk;
                oppDmg = oppDmg - plyrBlk;
            }
            cout << " of the damage, taking " << oppDmg;
            plyrHealth = plyrHealth - oppDmg;
            cout << endl << "Player Health: " << plyrHealth;
            cout << endl << "Opp Health: " << oppHealth;
        }
        //opponent attack - player dodge
        if (cpuCombat == 1 && cmbtAct == 3) {
            cout << endl;
            //opponent attack
            cout << oppName << " attacks " << endl;
            oppAtk = attack(oppStats[1], plyrStats[2]);
            if (oppAtk = 0) {
                cout << "but misses";
                oppDmg = 0;
            } else if (oppAtk >= 1) {
                cout << oppName << " strikes for ";
                oppDmg = getDamage(oppStats[1], plyrStats[2], oppAtk);
                cout << oppDmg << " undefended damage";
            }
            //player dodge against attack
            plyrDdge = getDodge(oppDmg, plyrStats[3]);
            cout << endl;
            cout << "You dodged ";
            if (plyrDdge > oppAtk) {
                cout << "all ";
                oppDmg = 0;
            } else {
                cout << plyrDdge;
                oppDmg = oppDmg - plyrDdge;
            }
            cout << " of the damage, taking" << oppDmg;
            plyrHealth = plyrHealth - oppDmg;
            cout << endl << "Player Health: " << plyrHealth;
            cout << endl << "Opp Health: " << oppHealth;
        }
        //opponent attacks - player paries
        if (cpuCombat == 1 && cmbtAct == 4) {
            cout << endl;
            //opponent attack
            cout << oppName << " attacks " << endl;
            oppAtk = attack(oppStats[1], plyrStats[2]);
            if (oppAtk = 0) {
                cout << "but misses";
                oppDmg = 0;
            } else if (oppAtk >= 1) {
                cout << oppName << " strikes for ";
                oppDmg = getDamage(oppStats[1], plyrStats[2], oppAtk);
                cout << oppDmg << " undefended damage";
            }
            oppDmg = attack(oppStats[1], plyrStats[2]);
            //player parry against attack
            plyrPrry = getParry(oppDmg, plyrStats[4]);
            if (plyrPrry > oppDmg) {
                cout << oppName << " attacks " << endl;
                cout << "You parry and counter for ";
                int counter = 7 / 100;
                plyrDmg = getDamage(plyrStats[1], oppStats[2], counter);
                oppHealth = oppHealth - plyrDmg;
                cout << plyrDmg;
            } else {
                cout << oppName << " attacks " << endl;
                cout << "You parry, taking no damage but are unable to counter";
            }
            cout << endl << "Player Health: " << plyrHealth;
            cout << endl << "Opp Health: " << oppHealth;
        }
        //opponent blocks - player attacks
        if (cpuCombat == 2 && cmbtAct == 1) {
            cout << endl;
            //player attack
            cout << "You attack " << endl;
            plyrAtk = attack(plyrStats[1], oppStats[2]);
            if (plyrAtk = 0) {
                cout << "but miss";
                plyrDmg = 0;
            } else if (plyrAtk >= 1) {
                cout << "striking for ";
                plyrDmg = getDamage(plyrStats[1], oppStats[2], plyrAtk);
                cout << plyrDmg << " undefended damage";
            }
            //opponent dodge against attack
            oppBlk = getBlock(plyrAtk, oppStats[2]);
            cout << oppName << " blocked ";
            if (oppBlk > plyrAtk) {
                cout << "all ";
                plyrDmg = 0;
            } else {
                cout << oppBlk;
                plyrDmg = plyrDmg - oppBlk;
            }
            cout << " of the damage, taking" << plyrDmg;
            oppHealth = oppHealth - plyrDmg;
            cout << endl << "Player Health: " << plyrHealth;
            cout << endl << "Opp Health: " << oppHealth;
        }
        //opponent blocks - player dodges
        if (cpuCombat == 2 && cmbtAct == 3) {
            //non combat action
            cout << endl;
            cout << oppName << " takes a defensive position";
            cout << endl;
            cout << "You step back from your opponent";
        }
        //opponent blocks - player paries
        if (cpuCombat == 2 && cmbtAct == 4) {
            //non combat action
            cout << endl;
            cout << oppName << " takes a defensive position";
            cout << endl;
            cout << "You look to deflect an attack that never comes";
        }
        //opponent dodges - player attacks
        if (cpuCombat == 3 && cmbtAct == 1) {
            cout << endl;
            //player attacks
            cout << "You attack " << endl;
            plyrAtk = attack(plyrStats[1], oppStats[2]);
            if (plyrAtk = 0) {
                cout << "but miss";
                plyrDmg = 0;
            } else if (plyrAtk >= 1) {
                plyrDmg = getDamage(plyrStats[1], oppStats[2], plyrAtk);
                cout << "and strike for " << plyrDmg << " damage";
            }
            cout << endl;
            //opponent dodges versus attack
            oppDdge = getDodge(plyrAtk, oppStats[3]);
            cout << oppName << " dodged ";
            if (oppDdge > plyrDmg) {
                cout << "all ";
            } else {
                cout << oppDdge;
            }
            cout << " of the damage";
            oppHealth = oppHealth - plyrDmg;
            cout << endl << "Player Health: " << plyrHealth;
            cout << endl << "Opp Health: " << oppHealth;
        }
        //opponent dodges - player blocks
        if (cpuCombat == 3 && cmbtAct == 2) {
            //non combat action
            cout << endl;
            cout << oppName << " slides away from you";
            cout << endl;
            cout << "You prepare to block an incoming attack";
        }
        //opponent dodges - player paries
        if (cpuCombat == 3 && cmbtAct == 4) {
            //non combat action
            cout << endl;
            cout << oppName << " jumps back, anticipating an attack";
            cout << endl;
            cout << "You anticipate an attack, but it never comes";
        }
        //opponent paries - player attacks
        if (cpuCombat == 4 && cmbtAct == 1) {
            cout << endl;
            plyrDmg = attack(plyrStats[1], oppStats[2]);
            oppPrry = getParry(plyrDmg, oppStats[4]);
            if (oppPrry > plyrDmg) {
                cout << "You attack" << endl;
                cout << oppName << "paries and counters for ";
                int counter = 7 / 100;
                oppDmg = getDamage(oppStats[1], plyrStats[2], counter);
                plyrHealth = plyrHealth - oppDmg;
                cout << oppDmg;
            } else {
                cout << "You attack " << endl;
                cout << oppName << " paries, taking no damage but is unable to counter";
            }
            cout << endl << "Player Health: " << plyrHealth;
            cout << endl << "Opp Health: " << oppHealth;
        }
        //opponent paries - player blocks
        if (cpuCombat == 4 && cmbtAct == 2) {
            //non combat action
            cout << endl;
            cout << oppName << " anticipates an attack, but it never comes";
            cout << endl;
            cout << "You take up a defensive stance, preparing to block";
        }
        //opponent paries - player dodges
        if (cpuCombat == 4 && cmbtAct == 3) {
            //non combat action
            cout << endl;
            cout << oppName << " moves to deflect an attack";
            cout << endl;
            cout << "You slide away from " << oppName;
        }
        if (plyrHealth <= 5 && plyrHealth >=0)
        {
            cout << "You are gravely wounded, will you yield to the emperor's will\n"
                    "or continue to fight?";
            cin >> wounded;
            if(wounded == 'y')
            {
                cout << endl << "The emperor's favor shines on you today, he wills you to live.";
            }
        }
        if (plyrHealth < 0)
        {
            cout << endl << "You have been killed in combat" << endl;
            exit(2);                    
        }
    }

    if (round < 5) {
        cout << endl << endl << "Advance to next day?(y or n)";
        cin >> advance;
        while (advance != 'y' && advance != 'n') {
            cout << endl << "You have entered an invalid entry, please re-enter: ";
            cin >> advance;
        }
        return advance;
    } else {
        cout << endl << "Thank you for playing Ave Imperator!";
        cout << endl;
        exit(1);
    }
}

int getCpuAction() {
    short oppCh = 0; //cpu choice

    //set random 1 through 5 for cpu
    oppCh = rand() % 4 + 1;

    return oppCh;
}