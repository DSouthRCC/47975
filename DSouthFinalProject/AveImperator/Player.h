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
    int plyrAtkP;
    int plyrAtkSp;
    int plyrBlk;
    int plyrDdge;
    int plyrPrry;
    int plyrHAdj;
    int plyrFAdj;
    int plyrAgAj;
    int plyrDfAj;
    int plyrMvAj;
    //int plyrFavor;

public:
    //default constructor

    Player() : Gladiator() {
        plyrName = "";
        plyrStyl = "";
        plyrAtkP = 0;
        plyrAtkSp = 0;
        plyrBlk = 0;
        plyrDdge = 0;
        plyrPrry = 0;
        plyrHAdj = 0;
        plyrFAdj = 0;
        plyrAgAj = 0;
        plyrDfAj = 0;
        plyrMvAj = 0;
    }

    Player(int hlt, int fat, int str, int agi, int def, int mvSp) :
    Gladiator(hlt, fat, str, agi, def, mvSp) {
        plyrName = "";
        plyrStyl = "";
        plyrAtkP = 0;
        plyrAtkSp = 0;
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

    Player(string name, string style, string weapon, int dmg, int speed, int reach, int wDfAdj, int wAgiAdj, int wFtiAdj, string armor, int aDefAdj, int aAgiAdj, int aFtiAdj, int aMvAdj) {
        plyrName = name;
        plyrStyl = style;
        plyrWpn.set(weapon, dmg, speed, reach, wDfAdj, wAgiAdj, wFtiAdj);
        plyrArmr.set(armor, aDefAdj, aAgiAdj, aFtiAdj, aMvAdj);
    }
    // Mutator functions
    void setAttributes(int hlt, int fat, int str, int agi, int def, int mvSpd);
    void setPlyrAtkP(int wpDmg, int wpSpd); //str, wpDmg, wpSpd
    void setPlyrAtkSp(int wpSpd); //wp spd, agility, move speed
    void setPlyrBlk(int wpDef, int arDef); //wep def adj, armr def adj, str def
    void setPlyrDdge(); //armor mv adj, agility, mvsp
    void setPlyrPrry(); //str, agi, wpRch

    string getPlryName() const {
        return plyrName;
    }

    string getPlryStyl() const {
        return plyrStyl;
    }

    int getPlryAtkP() const {
        return plyrAtkP;
    }

    int getPlryAtkSp() const {
        return plyrAtkSp;
    }
    
    int getPlryBlk() const {
        return plyrBlk;
    }

    int getPlryDdge() const {
        return plyrDdge;
    }

    int getPlryPrry() const {
        return plyrPrry;
    }

    //virtual variables
    virtual int adjHealth(int) const;
    virtual int adjFatigue(int, int, int) const;
    virtual int adjStrength(int) const;
    virtual int adjAgility(int, int, int) const;
    virtual int adjDefense(int, int, int) const;
    virtual int adjMovement(int, int) const;

    //print functions
    void prntPlyrStrgs() const;
    void prntPlyrStats() const;
};
#endif