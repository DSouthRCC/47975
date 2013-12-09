#include<iostream>
#include "Player.h"
using namespace std;

short Player::adjHealth(short hlth) const {
    short health; //new health
    //calculate new
    health = baseHlth + hlth;
    //return new health
    return health;
}

short Player::adjFatigue(short fti) const {
    short fatigue; //new fatigue
    //calculate new
    fatigue = baseFti + fti;
    //return new fatigue
    return fatigue;
}

short Player::adjStrength(short str) const {
    short strength; //new strength
    //calculate new
    strength = baseStr + str;
    //return new strength
    return strength;
}

short Player::adjAgility(short agi) const {
    short agility; //new agility
    //calculate new
    agility = baseAgi + agi;
    //return new agility
    return agility;
}

short Player::adjDefense(short def) const {
    short defense; //new defense
    //calculate new
    defense = baseDef + def;
    //return new defense
    return defense;
}

short Player::adjMovement(short mv) const {
    short movement; //new movement
    //calculate new
    movement = baseMvSp + mv;
    //return new movement
    return movement;
}

void Player::setAttributes(short hlt, short fat, short str, short agi, short def, short mvSpd) {
    baseHlth = hlt; //store adjusted health
    baseFti = fat; //store adjusted fatigue
    baseStr = str; //store adjusted strength
    baseAgi = agi; //store adjusted agility
    baseDef = def; //store adjusted defense
    baseMvSp = mvSpd; //store adjusted movement
}

void Player::setPlyrAtkP(short wpDmg, short wpSpd) {
    plyrAtkP = ((baseStr * (wpDmg + wpSpd))*.5);
}

void Player::setPlyrBlk() {
    plyrBlk = ((baseStr + baseDef)*.8);
}

void Player::setPlyrDdge(short moveSpd) {
    plyrDdge = ((baseAgi + moveSpd)*.5);
}

void Player::setPlyrPrry(short wpReach) {
    plyrPrry = (((baseStr + baseAgi) * wpReach)*.5);
}

void Player::prntPlyrStrgs() const {
    cout << "Gladiator Name: " << plyrName << endl << endl;
    cout << "Player Health: " << baseHlth << endl;
    prntBase();
    cout << endl;
    cout << "Fighting Style: " << plyrStyl << endl << endl;
    plyrWpn.prntWep();
    cout << endl;
    plyrArmr.prntArmr();
    cout << endl;
}

void Player::prntPlyrStats() const {
    cout << "Combat Stats: " << endl;
    cout << "\tAttack Power: " << plyrAtkP << endl;
    cout << "Dodge Skill: " << plyrDdge << endl;
    cout << "Parry Skill: " << plyrPrry << endl;
}