//functional includes
#include <iostream>
#include <cmath>
#include <cstdlib>

//class includes
#include "Player.h"
#include "PlayerStats.h"

using namespace std;

//no global constants

//function prototypes
Player mkStats();

//begin program
int main() {

	//class definitions
	Gladiator player (100,20,10,10,10,10);
	Gladiator opp1 (100,20,10,10,10,10);
	Player stats;
	//get user choices
	stats = mkStats();
	//display user choices
	stats.prntPlyrStrgs();

	//run combat loop
		//get opponent
		//display resolution

	//victory or death

	//exit program
	return 0;
}

Player mkStats() {

	Player stats;

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
	//calculatables
	short attkPwr; //calculated attack power
	short dodge; //calculated dodge
	short parry; //calculated parry
	short plyrRch; //calculated total reach

	//get player name
	cout << "What is your name, Gladiator! ";
	getline(cin, name);
	//set name
	//stats.plyrName = name;
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
		plyrfati = 16;
		plyrAgi = 14;
		plyrDef = 10;
		plyrMvSp = 10;
	}
	else if (getPlyrStnc = 2) {
		style = "Tactful";
		plyrHlth = 0;
		plyrStr = 13;
		plyrfati = 12;
		plyrAgi = 13;
		plyrDef = 12;
		plyrMvSp = 10;
	}
	else if (getPlyrStnc = 3) {
		style = "Brute";
		plyrHlth = 10;
		plyrStr = 17;
		plyrfati = 11;
		plyrAgi = 12;
		plyrDef = 10;
		plyrMvSp = 10;
	}
	else if (getPlyrStnc = 4) {
		style = "Tank";
		plyrHlth = 20;
		plyrStr = 13;
		plyrfati = 10;
		plyrAgi = 10;
		plyrDef = 17;
		plyrMvSp = 10;
	}
	//fill classes
	stats (name, style, weapon, wpDmg, wpSpd, wpRch, wpDef, wpAgi, armor, arDef, arAgi);
	stats.setAttributes(plyrHlth, plyrStr, plyrFati, plyrAgi, plyrDef, plyrMvSp);
	stats.setPlyrAtkP(plyrStr, wpDmg, wpSpd);
	//return
	return stats;
}