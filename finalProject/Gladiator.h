// Specification file for the Gladiator class
#ifndef GLADIATOR_H
#define GLADIATOR_H
#include <string>
using namespace std;

class Gladiator {
protected:
    short baseHlth; //gladiator health
    short baseFti; //gladiator fatigue
    short baseStr; //base strength
    short baseAgi; //base agility
    short baseDef; //base defense
    short baseMvSp; //base move speed

public:
    //default constructor

    Gladiator() {
        baseHlth = 100;
        baseFti = 20;
        baseStr = 10;
        baseAgi = 10;
        baseDef = 10;
        baseMvSp = 10;
    }
    //base constructor

    Gladiator(short hlt, short fat, short str, short agi, short def, short mvSp) {
        set(hlt, fat, str, agi, def, mvSp);
    }
    //set values

    void set(short hlt, short fat, short str, short agi, short def, short mvSp) {
        baseHlth = hlt;
        baseFti = fat;
        baseStr = str;
        baseAgi = agi;
        baseDef = def;
        baseMvSp = mvSp;
    }
    //accessors

    short getHealth() const {
        return baseHlth;
    }

    short getFatigue() const {
        return baseFti;
    }

    short getStrength() const {
        return baseStr;
    }

    short getAgility() const {
        return baseAgi;
    }

    short getDefense() const {
        return baseDef;
    }

    short getMoveSpd() const {
        return baseMvSp;
    }

    //virtual manipulators
    virtual short adjHealth(short) const = 0;
    virtual short adjFatigue(short) const = 0;
    virtual short adjStrength(short) const = 0;
    virtual short adjAgility(short) const = 0;
    virtual short adjDefense(short) const = 0;
    virtual short adjMovement(short) const = 0;

    //display
    void prntBase() const;
};
#endif 