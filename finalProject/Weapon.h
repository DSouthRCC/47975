// Specification file for the Weapon class
#ifndef WEAPON_H
#define WEAPON_H
#include <string>

using namespace std;

class Weapon {
private:
    string wpName;
    short wpDamage;
    short wpSpeed;
    short wpReach;
    short wpDefAdj;
    short wpAgiAdj;
    short wpFtiAdj;

public:
    //default constructor
    Weapon() {
        set("", 0, 0, 0, 0, 0, 0);
    }

    //build constructor
    Weapon(string weapon, short dmg, short speed, short reach, short wDefAdj, short wAgiAdj, short wFtiAdj) {
        set(weapon, dmg, speed, reach, wDefAdj, wAgiAdj, wFtiAdj);
    }

    //mutators
    void set(string weapon, short dmg, short speed, short reach, short wDefAdj, short wAgiAdj, short wFtiAdj) {
        wpName = weapon;
        wpDamage = dmg;
        wpSpeed = speed;
        wpReach = reach;
        wpDefAdj = wDefAdj;
        wpAgiAdj = wAgiAdj;
        wpFtiAdj = wFtiAdj;
    }

    string getWpName() const {
        return wpName;
    }

    short getWpDamage() const {
        return wpDamage;
    }

    short getWpSpeed() const {
        return wpSpeed;
    }

    short getWpReach() const {
        return wpReach;
    }

    short getWpDefAdj() const {
        return wpDefAdj;
    }

    short getWpAgiAdj() const {
        return wpAgiAdj;
    }

    short getWpFtiAdj() const {
        return wpFtiAdj;
    }    
    
    void prntWep() const {
        cout << "Weapon\t" << "Damage\t" << "Speed\t" << "Reach\t" << "Def Adj\t" << "Agi Adj\t" << "Fatigue Adj" << endl
                << wpName << "\t" << wpDamage << "\t" << wpSpeed << "\t" << wpReach << "\t" << wpDefAdj << "\t" << wpAgiAdj << "\t" << wpFtiAdj << endl;
    }

};
#endif