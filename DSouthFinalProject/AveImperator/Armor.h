// Specification file for the Armor class
#ifndef ARMOR_H
#define ARMOR_H
#include <string>
#include <iomanip>

using namespace std;

class Armor {
private:
    string arName;
    int arDefAdj;
    int arAgiAdj;
    int arFtiAdj;
    int arMvAdj;

public:
    //default constructor

    Armor() {
        set("", 0, 0, 0, 0);
    }

    //base constructor

    Armor(string armor, int aDefAdj, int aAgiAdj, int aFtiAdj, int aMvAdj) {
        set(armor, aDefAdj, aAgiAdj, aFtiAdj, aMvAdj);
    }

    //mutators

    void set(string armor, int aDefAdj, int aAgiAdj, int aFtiAdj, int aMvAdj) {
        arName = armor;
        arDefAdj = aDefAdj;
        arAgiAdj = aAgiAdj;
        arFtiAdj = aFtiAdj;
        arMvAdj = aMvAdj;
    }

    string getArName() const {
        return arName;
    }

    int getArDefAdj() const {
        return arDefAdj;
    }

    int getArAgiAdj() const {
        return arAgiAdj;
    }
    
    int getArFtiAfj() const {
        return arFtiAdj;
    }
    
    int getArMvAdj() const {
        return arMvAdj;
    }
    
    void prntArmr() const {
        cout << "Armor" << setw(arName.length()+4) << "Def Adj" << setw(9) << "Agi Adj" << setw(13) << "Fatigue Adj" << setw(14) << "Movement Adj" << endl
                << arName << setw(9) << arDefAdj << setw(9) << arAgiAdj << setw(13) << arFtiAdj << setw(14) << arMvAdj << endl;
    }

};
#endif