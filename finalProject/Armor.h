// Specification file for the Armor class
#ifndef ARMOR_H
#define ARMOR_H
#include <string>

using namespace std;

class Armor {
private:
    string arName;
    short arDefAdj;
    short arAgiAdj;
    short arFtiAdj;
    short arMvAdj;

public:
    //default constructor

    Armor() {
        set("", 0, 0, 0, 0);
    }

    //base constructor

    Armor(string armor, short aDefAdj, short aAgiAdj, short aFtiAdj, short aMvAdj) {
        set(armor, aDefAdj, aAgiAdj, aFtiAdj, aMvAdj);
    }

    //mutators

    void set(string armor, short aDefAdj, short aAgiAdj, short aFtiAdj, short aMvAdj) {
        arName = armor;
        arDefAdj = aDefAdj;
        arAgiAdj = aAgiAdj;
        arFtiAdj = aFtiAdj;
        arMvAdj = aMvAdj;
    }

    string getArName() const {
        return arName;
    }

    short getArDefAdj() const {
        return arDefAdj;
    }

    short getArAgiAdj() const {
        return arAgiAdj;
    }
    
    short getArFtiAfj() const {
        return arFtiAdj;
    }
    
    short getArMvAdj() const {
        return arMvAdj;
    }
    
    void prntArmr() const {
        cout << "Armor\t" << "Def Adj\t" << "Agi Adj\t" << "Fatigue Adj\t" << "Movement Adj\t" << endl
                << arName << "\t" << arDefAdj << "\t" << arAgiAdj << "\t" << arFtiAdj << "\t" << arMvAdj << endl;
    }

};
#endif