// Specification file for the Gladiator class
#ifndef GLADIATOR_H
#define GLADIATOR_H
#include <string>
using namespace std;

class Gladiator {
protected:
	short health; //gladiator health
    short fatigue; //gladiator fatigue
	short strength; //base strength
	short agility; //base agility
    short defense; //base defense
	short moveSpd; //base move speed

public:
    //default constructor
    Gladiator() {
        health = 0;
        fatigue = 0;
        strength = 0;
		agility = 0;
        defense = 0;
		moveSpd = 0;
    }
    //base constructor
    Gladiator(short hlt, short fat, short str, short agi, short def, short mvSp) {
        set(hlt, fat, str, agi, def, mvSp);
    }
	//set values
    void set(short hlt, short fat, short str, short agi, short def, short mvSp) {
        health = hlt;
        fatigue = fat;
        strength = str;
		agility = agi;
        defense = def;
		moveSpd = mvSp;
    }
	//accessors
    short getHealth() const {
        return health;
    }   
    short getFatigue() const {
        return fatigue;
    }
	short getStrength() const {
        return strength;
    }
	short getAgility() const {
        return agility;
    }
    short getDefense() const {
        return defense;
    }
	 short getMoveSpd() const {
        return moveSpd;
    }
	//display
	void prntBase() const {
		 cout << "Base Stats: " << endl;
		cout << "Health\t" << "Fatigue\t" << "Strength\t" << "Agility\t" << "Defense\t" << "Movement\t" << endl
		<< health << "\t" << fatigue << "\t" << strength << "\t" << agility << "\t" << defense << "\t" << moveSpd << endl;
	}
};
#endif 