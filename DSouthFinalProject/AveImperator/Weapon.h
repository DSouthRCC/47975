// Specification file for the Weapon class
#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <iomanip>
using namespace std;

class Weapon {
private:
    string wpName;
    int wpDamage;
    int wpSpeed;
    int wpReach;
    int wpDefAdj;
    int wpAgiAdj;
    int wpFtiAdj;

public:
    //default constructor
    Weapon() {
        set("", 0, 0, 0, 0, 0, 0);
    }

    //build constructor
    Weapon(string weapon, int dmg, int speed, int reach, int wDefAdj, int wAgiAdj, int wFtiAdj) {
        set(weapon, dmg, speed, reach, wDefAdj, wAgiAdj, wFtiAdj);
    }

    //mutators
    void set(string weapon, int dmg, int speed, int reach, int wDefAdj, int wAgiAdj, int wFtiAdj) {
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

    int getWpDamage() const {
        return wpDamage;
    }

    int getWpSpeed() const {
        return wpSpeed;
    }

    int getWpReach() const {
        return wpReach;
    }

    int getWpDefAdj() const {
        return wpDefAdj;
    }

    int getWpAgiAdj() const {
        return wpAgiAdj;
    }

    int getWpFtiAdj() const {
        return wpFtiAdj;
    }    
    
    void prntWep() const {
        cout << "Weapon" << setw(wpName.length()+2) << "Damage" << setw(8) << "Speed" << setw(7) << "Reach" << setw(9) << "Def Adj" << setw(9) << "Agi Adj" << setw(13) << "Fatigue Adj" << endl
                << wpName << setw(8) << wpDamage << setw(8) << wpSpeed << setw(7) << wpReach << setw(9) << wpDefAdj << setw(9) << wpAgiAdj << setw(13) << wpFtiAdj << endl;
    }
};
#endif