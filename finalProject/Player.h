// Specification file for the Player class
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Gladiator.h"
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class Player : public Gladiator {
private:
    Weapon plyrWpn;
    Armor plyrArmr;
    string plyrName;
    string plyrStyl;
    short plyrAtkP;
    short plyrBlk;
    short plyrDdge;
    short plyrPrry;
    short plyrHAdj;
    short plyrFAdj;
    short plyrAgAj;
    short plyrDfAj;
    short plyrMvAj;
    //short plyrFavor;

public:
    //default constructor

    Player() : Gladiator() {
        plyrName = "";
        plyrStyl = "";
        plyrAtkP = 0;
        plyrBlk = 0;
        plyrDdge = 0;
        plyrPrry = 0;
        plyrHAdj = 0;
        plyrFAdj = 0;
        plyrAgAj = 0;
        plyrDfAj = 0;
        plyrMvAj = 0;
    }

    Player(short hlt, short fat, short str, short agi, short def, short mvSp) :
    Gladiator(hlt, fat, str, agi, def, mvSp) {
        plyrName = "";
        plyrStyl = "";
        plyrAtkP = 0;
        plyrBlk = 0;
        plyrDdge = 0;
        plyrPrry = 0;
        plyrHAdj = 0;
        plyrFAdj = 0;
        plyrAgAj = 0;
        plyrDfAj = 0;
        plyrMvAj = 0;
    }
    //base constructor

    Player(string name, string style, string weapon, short dmg, short speed, short reach, short wDfAdj, short wAgiAdj, short wFtiAdj, string armor, short aDefAdj, short aAgiAdj, short aFtiAdj, short aMvAdj) {
        plyrName = name;
        plyrStyl = style;
        plyrWpn.set(weapon, dmg, speed, reach, wDfAdj, wAgiAdj, wFtiAdj);
        plyrArmr.set(armor, aDefAdj, aAgiAdj, aFtiAdj, aMvAdj);
    }
    // Mutator functions
    void setAttributes(short hlt, short fat, short str, short agi, short def, short mvSpd);
    void setPlyrAtkP(short wpDmg, short wpSpd); //str, wpDmg, wpSpd
    void setPlyrBlk(); //str def
    void setPlyrDdge(short moveSpd); //agility, mvsp
    void setPlyrPrry(short wpReach); //str, agi, wpRch

    string getPlryName() const {
        return plyrName;
    }

    string getPlryStyl() const {
        return plyrStyl;
    }

    short getPlryAtkP() const {
        return plyrAtkP;
    }
    
    short getPlryBlk() const {
        return plyrBlk;
    }

    short getPlryDdge() const {
        return plyrDdge;
    }

    short getPlryPrry() const {
        return plyrPrry;
    }

    //virtual variables
    virtual short adjHealth(short) const;
    virtual short adjFatigue(short) const;
    virtual short adjStrength(short) const;
    virtual short adjAgility(short) const;
    virtual short adjDefense(short) const;
    virtual short adjMovement(short) const;

    //print functions
    void prntPlyrStrgs() const;
    void prntPlyrStats() const;
};
#endif