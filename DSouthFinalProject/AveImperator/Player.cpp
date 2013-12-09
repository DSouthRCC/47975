//Specification file for Player implimentation
#include<iostream>
#include <iomanip>
#include "Player.h"
using namespace std;

int Player::adjHealth(int hlth) const {
    int health; //new health
    //calculate new
    health = baseHlth + hlth;
    //return new health
    return health;
}

int Player::adjFatigue(int fti, int wpFti, int arFti) const {
    int fatigue; //new fatigue
    //calculate new
    fatigue = baseFti + fti - (wpFti + arFti);
    //return new fatigue
    return fatigue;
}

int Player::adjStrength(int str) const {
    int strength; //new strength
    //calculate new
    strength = baseStr + str;
    //return new strength
    return strength;
}

int Player::adjAgility(int agi, int wpAgi, int arAgi) const {
    int agility; //new agility
    //calculate new
    agility = baseAgi + agi - (wpAgi + arAgi);
    //return new agility
    return agility;
}

int Player::adjDefense(int def, int wpDef, int arDef) const {
    int defense; //new defense
    //calculate new
    defense = baseDef + def + wpDef + arDef;
    //return new defense
    return defense;
}

int Player::adjMovement(int mv, int arMv) const {
    int movement; //new movement
    //calculate new
    movement = baseMvSp + mv - arMv;
    //return new movement
    return movement;
}

void Player::setAttributes(int hlt, int fat, int str, int agi, int def, int mvSpd) {
    baseHlth = hlt; //store adjusted health
    baseFti = fat; //store adjusted fatigue
    baseStr = str; //store adjusted strength
    baseAgi = agi; //store adjusted agility
    baseDef = def; //store adjusted defense
    baseMvSp = mvSpd; //store adjusted movement
}

void Player::setPlyrAtkP(int wpDmg, int wpSpd) {
    plyrAtkP = ((baseStr * (wpDmg + wpSpd))/4);
}

void Player::setPlyrAtkSp(int wpSpd) {
    plyrAtkSp = ((baseAgi + (wpSpd + baseMvSp))*.9);
}

void Player::setPlyrBlk(int wpDef, int arDef) {
    plyrBlk = (wpDef+arDef+((baseStr + baseDef)/2));
}

void Player::setPlyrDdge() {
    plyrDdge = ((baseAgi + baseMvSp)/2);
}

void Player::setPlyrPrry() {
    plyrPrry = ((baseStr + baseAgi)*.6);
}

void Player::prntPlyrStrgs() const {
    cout << endl << "--------------------------------------------------------------" << endl;
    cout << "Gladiator Name: " << plyrName << endl << endl;
    cout << "Fighting Style: " << plyrStyl << endl << endl; 
    plyrWpn.prntWep();
    cout << endl;
    plyrArmr.prntArmr();
    cout << endl;
    prntBase();
    cout << endl;
}

void Player::prntPlyrStats() const {
    cout << "Combat Stats: " << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Attack Power: " << plyrAtkP << endl;
    cout << "Attack Speed: " << plyrAtkSp << endl;
    cout << "Block Rating: " << plyrBlk << endl;
    cout << "Dodge Rating: " << plyrDdge << endl;
    cout << "Parry Rating: " << plyrPrry << endl;
    cout << "--------------------------------------------------------------" << endl;
}