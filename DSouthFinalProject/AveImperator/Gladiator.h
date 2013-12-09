// Specification file for the Gladiator class
#ifndef GLADIATOR_H
#define GLADIATOR_H
#include <string>
using namespace std;

class Gladiator {
protected:
    int baseHlth; //gladiator health
    int baseFti; //gladiator fatigue
    int baseStr; //base strength
    int baseAgi; //base agility
    int baseDef; //base defense
    int baseMvSp; //base move speed

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

    Gladiator(int hlt, int fat, int str, int agi, int def, int mvSp) {
        set(hlt, fat, str, agi, def, mvSp);
    }
    //set values

    void set(int hlt, int fat, int str, int agi, int def, int mvSp) {
        baseHlth = hlt;
        baseFti = fat;
        baseStr = str;
        baseAgi = agi;
        baseDef = def;
        baseMvSp = mvSp;
    }
    //accessors

    int getHealth() const {
        return baseHlth;
    }

    int getFatigue() const {
        return baseFti;
    }

    int getStrength() const {
        return baseStr;
    }

    int getAgility() const {
        return baseAgi;
    }

    int getDefense() const {
        return baseDef;
    }

    int getMoveSpd() const {
        return baseMvSp;
    }

    //virtual manipulators
    virtual int adjHealth(int) const = 0;
    virtual int adjFatigue(int, int, int) const = 0;
    virtual int adjStrength(int) const = 0;
    virtual int adjAgility(int, int, int) const = 0;
    virtual int adjDefense(int, int, int) const = 0;
    virtual int adjMovement(int, int) const = 0;

    //display
    void prntBase() const;
};
#endif 